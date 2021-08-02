#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define MAX 126
#define INF 987654321

using namespace std;

int dist[MAX][MAX];
int node[MAX][MAX];
vector<pair<pair<int, int>, int>> connect[MAX][MAX];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int n;
bool Input() {
	int a;
	cin >> n;
	if (n == 0)
		return false;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> a;
				dist[i][j] = a;
				node[i][j] = INF;
			}
		}
		return true;
	}
}
void make_connect() {
	node[1][1] = dist[1][1];
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int y = i + dy[k];
				int x = j + dx[k];
				if (y == 1 && x == 1) continue;
				if (y < 1 || y > n || x < 1 || x > n) continue;
				//connect[i][j].clear;
				connect[i][j].push_back(make_pair(make_pair(y, x),dist[y][x]));
			}
		}
	}
}

void dijkstra(int a, int b)
{
	priority_queue < pair<pair<int, int>, int>> q;
	q.push( make_pair ( make_pair(a, b), -1*dist[a][b]));
	while (!q.empty())
	{
		int currentY = q.top().first.first;
		int currentX = q.top().first.second;
		int distance = -1*q.top().second;
		q.pop();

		if (node[currentY][currentX] < distance) continue;

		for (int i = 0; i < connect[currentY][currentX].size(); i++)
		{
			int nextY = connect[currentY][currentX][i].first.first;
			int nextX = connect[currentY][currentX][i].first.second;
			int next_dist = distance + connect[currentY][currentX][i].second;

			if (node[nextY][nextX] > next_dist)
			{
				node[nextY][nextX] = next_dist;
				q.push(make_pair(make_pair(nextY, nextX), -1 * next_dist));
			}

		}
	}

}

int main(void) {
	int cnt = 0;
	while (Input())
	{
		memset(connect, 0, sizeof(connect));
		cnt++;
		node[1][1] = dist[1][1];
		make_connect();
		dijkstra(1, 1);
		cout << "Problem "<< cnt << ": " << node[n][n] << "\n";
	}
}
//https://www.acmicpc.net/problem/4485
//다익스트라로 구현 시도
//210802 예제 출력에 문제가 발생해서 손코딩으로 문제를 3시간동안 찾았는데 안나와서 디버깅으로 찾으니 벡터 초기화를 안함...
//벡터 초기화구문 넣고 init() 삭제 후 정답처리 받음
