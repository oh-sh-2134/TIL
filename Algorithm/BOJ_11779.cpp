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


