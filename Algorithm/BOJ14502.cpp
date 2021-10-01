#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

enum {
	None,
	Wall,
	Virus
};

int arr[8][8];
int temp[8][8];
int n, m;
int sol;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

void Copy(int(*a)[8], int(*b)[8]) 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			a[i][j] = b[i][j];
	}
}


void BFS() {
	
	int bfs[8][8];
	Copy(bfs, temp);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (bfs[i][j] == Virus)
				q.push({ i, j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 > nx || nx >= n || 0 > ny || ny >= m)
					continue;
			if (bfs[nx][ny] == None)
			{
				bfs[nx][ny] = Virus;
				q.push({ nx, ny });
			}
			
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (bfs[i][j] == None)
				cnt += 1;
		}
	}
	sol = max(sol, cnt);
}


void OnWall(int cnt) {
	if (cnt == 3) 
	{
		BFS();
		return;
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (temp[i][j] == None) 
			{
				temp[i][j] = Wall;
				OnWall(cnt + 1);
				temp[i][j] = None;
			}
		}
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				Copy(temp, arr);
				temp[i][j] = Wall;
				OnWall(1);
				temp[i][j] = None;
			}
		}
	}
}

int main(void) {
	Input();
	solution();
	cout << sol;
	return 0;
}
//https://www.acmicpc.net/problem/14502
//enum을 이용해서 상태를 표현함 / 재귀를 통해 벽을 세운 후 모든케이스를 확인하기위해 브루트포스 사용했고 바이러스를 퍼트리는 것과 빈공간 확인을 위해 BFS를 사용 함