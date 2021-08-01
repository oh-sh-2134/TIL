#include<iostream>
#include<queue>
#include<vector>
#define MAX 125
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

void init(int a, int b) {
	node[a][b] = dist[a][b];
	for (int k = 0; k < 4; k++)
	{
		int y = a + dy[k];
		int x = b + dx[k];

		if (y < 1 || y > n || x < 1 || x > n) continue;
		node[y][x] = dist[y][x];
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

			if (dist[nextY][nextX] > next_dist)
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
		cnt++;
		init(1, 1);
		make_connect();
		dijkstra(1, 1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				
				cout << node[i][j] << " " ;
			}
			cout << "\n";
		}
		cout << "Problem "<< cnt << ": " << node[n][n] << "\n";
	}
}
//https://www.acmicpc.net/problem/4485
//다익스트라로 구현 시도
