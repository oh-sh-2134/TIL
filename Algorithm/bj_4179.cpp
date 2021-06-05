#include<iostream>
#include<queue>
#define MAX 1000
using namespace std;

int R,C;
int field[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

queue<pair<int, int>> q;

void bfs() {
	q.push({ jx,jy });
	visit[jx][jy] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (p[x][y] == 0 && (x == 1 || x == N || y == 1 || y == M)) {
			res = visit[x][y];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny < 1 || nx>N || ny>M) continue;
			if (p[nx][ny] == 1) continue;
			if (visit[nx][ny] == -1) {
				visit[nx][ny] = visit[x][y] + 1;
				p[nx][ny] = p[x][y];
				q.push({ nx,ny });
			}
		}
	}
}
void Input()
{
	cin >> R >> C;
	for(int i=0; i<R; i++)
	{
		for(int j=0;j<C;j++)
		{
			cin >> field[i][j];
		}
	}
}

void solution()
{



}

int main(void){
	Input();


}
//https://www.acmicpc.net/problem/4179
//우선큐에 넣어야 할 것을 찾아야함
