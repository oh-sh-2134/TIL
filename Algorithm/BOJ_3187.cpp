#include<iostream>
#include<queue>
#include<string.h>
#define MAX 250

using namespace std;

char field[MAX][MAX];
bool visited[MAX][MAX];
int vk[2][2];
// v count = vk[0][0]
// k count = vk[1][0]
// total == vk[][1]

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;


void Input() {
	char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			field[i][j] = c;
		}
	}
}

void bfs(int a, int b)
{
	queue<pair<int, int>>q;
	q.push(make_pair(a, b));
	visited[a][b] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (field[y][x] == 'v')
		{
			vk[0][0]++;
		}
		else if (field[y][x] == 'k')
		{
			vk[1][0]++;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (field[ny][nx] != '#' && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}

	
	if (vk[0][0] < vk[1][0])
		vk[0][0] = 0;
	else if (vk[0][0] >= vk[1][0])
		vk[1][0] = 0;
	vk[0][1] += vk[0][0];
	vk[1][1] += vk[1][0];
	vk[0][0] = 0;
	vk[1][0] = 0;
}


int main() {
	memset(field, '#', sizeof(field));
	Input();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (field[i][j] != '#' && !visited[i][j])
			{
				bfs(i, j);
			}
		}
	}
	cout << vk[1][1] << " " << vk[0][1];
}
//https://www.acmicpc.net/problem/3187 
//BFS 풀이 / BFS 함수에서 시작 (y, x) 좌표 누락 수정, 출력 순서 수정 후 정답처리
//vk함수는 BFS에서 양과 늑대의 숫자 카운팅과 토탈 숫자 카운팅을 담기 위한 함수
