#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
#define MAX 1001
#define INF 987654321

vector<pair<int, int>> connect[MAX];

int route[MAX];
int node[MAX];
int S, D;

void Input() {
	int cont, T;
	int a, b,c;
	cin >> cont >> T;
	for(int i = 1; i<= cont ; i++) node[i] = INF;
	for(int i = 1; i<=T; i++)
	{
		
		cin >> a >> b >> c;
		connect[a].push_back(make_pair(b,c));
	}
	cin >> S >> D;
}

void Dijkstra(int start)
{
	node[start] = 0;
	priority_queue<pair<int, int>>q;
	q.push(make_pair(0, start));
	while (!q.empty())
	{
		int current_dist = -q.top().first;
		int current = q.top().second;
		q.pop();
		if (current_dist > node[current]) continue;

		for (int i = 0; i < connect[current].size(); i++)
		{
			int next = connect[current][i].first;
			int next_dist = current_dist + connect[current][i].second;
			if (node[next] > next_dist)
			{
			{
				node[next] = next_dist;
				q.push(make_pair(-next_dist, next));
				route[next] = current;
			}
		}
	}
}

void solution() {
	stack<int> rt;
	Dijkstra(S);
	int visited = D;
	while (visited)
	{

		rt.push(visited);
		if (visited == S) break;
		visited = route[visited];
	}
	cout << node[D] << "\n";
	cout << rt.size() << "\n";
	while (!rt.empty())
	{
		cout << rt.top() << " ";
		rt.pop();
	}
}

int main(void) 
{
	Input();
	solution();
}

//https://www.acmicpc.net/problem/11779
//정답 예제는 1 3 5인데 1 4 5가 출력이 되어 고민을 엄청하다 질문을 올렸는데
//스페셜저지문제 경우 정답이 여러개일수 있다고 함 -> 정답처리 받음
//다익스트라를 이용해서 풀고 최단거리로 이동하는 경로도 출력하는 문제
//최단거리를 갱신할때마다 route[next] = current 로 업데이트하는데 이 코드의 의미는 next경로로 가기위한 최단거리는 current라는 것을 의미함
//경로 업데이트 하는부분의 아이디어를 떠올리기가 힘들었음
