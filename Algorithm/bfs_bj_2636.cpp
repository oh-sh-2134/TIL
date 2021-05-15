#include<iostream>
#include<queue>

#define MAX 100

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int cheese[MAX][MAX];
bool visited[MAX][MAX];
int n, m, last_cheese, hours;

int CheeseCheck() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cheese[i][j] == 1) {
				cnt++;
			}
		}
	}

	if (cnt)
		last_cheese = cnt;


	return cnt;
}

void Airing()
{
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!visited[ny][nx] && !cheese[ny][nx])
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

void Melting()
{
	queue<pair<int, int>>cheese_q;
	queue<pair<int, int>>melting_q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cheese[i][j] == 1) {
				visited[i][j] = true;
				cheese_q.push(make_pair(i, j));
				while (!cheese_q.empty())
				{
					int y = cheese_q.front().first;
					int x = cheese_q.front().second;
					cheese_q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (!cheese[ny][nx] && visited[ny][nx]) melting_q.push(make_pair(y, x));
						if (cheese[ny][nx] && (!visited[ny][nx]))
						{
							visited[ny][nx] = true;
							cheese_q.push(make_pair(ny, nx));
						}
					}
				}
			}
		}
	}
	while (!melting_q.empty())
	{
		int y = melting_q.front().first;
		int x = melting_q.front().second;
		melting_q.pop();
		cheese[y][x] = 0;
	}
}

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> cheese[i][j];
		}
	}
}

void reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}
}
int main(void) {
	Input();
	while(CheeseCheck())
	{
		reset();
		Airing();
		Melting();
		hours++;
	}

	cout << hours << "\n" << last_cheese;
}
//https://www.acmicpc.net/problem/2636
//0511 빙하문제랑 비슷하다고 생각했는데 치즈 구멍안에서는 치즈가 녹지 않는다는 점을 놓침
//0512 테두리는 치즈도 공기도 차지 않는 공간임으로 (0,0)부터 BFS를 돌려 공기 부분을 처리
//0514 각각의 기능들을 함수화 시켰고 기본 예저는 맞으나 제출시 8%에서 바운더리 에러가 나서 
