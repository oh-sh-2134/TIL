#include<iostream>
#include<queue>
#include<vector>
#define MAX 125

using namespace std;

int dist[MAX][MAX];
int node[MAX][MAX];
vector<pair<pair<int, int>, int>> connect[MAX][MAX];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int n;
bool Input() {
	cin >> n;
	if (n == 0)
		return false;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int a;
				cin >> a;
				dist[i][j] = a;
			}
		}
		return true;
	}
}

void make_connect() {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int y = i + dy[k];
				int x = j + dx[k];

				if (y < 1 || y > n || x < 1 || x > n) continue;
				connect[i][j].push_back(make_pair(make_pair(y, x),dist[i][j]));
			}
		}
	}
}

int dijkstra(int a, int b)
{
	priority_queue < pair<pair<int, int>, int>> q;
	q.push( make_pair ( make_pair(a, b), dist[a][b]));
	while (!q.empty())
	{
		int currentY = q.top().first.first;
		int currentX = -1*q.top().first.second;
		int distance = q.top().second;
		q.pop();

		if (dist[currentY][currentX] < distance) continue;

		for (int i = 0; i < connect[currentY][currentX].size(); i++)
		{
			int next = connect[currentY][currentX][i];

		}
	}

}
//https://www.acmicpc.net/problem/4485
//다익스트라로 구현 시도