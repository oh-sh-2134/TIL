#include<iostream>
#include<queue>
#include<cstring>
#define MAX 1001
using namespace std;
int sol = 1000000000;
int R, C;
int field[MAX][MAX];
int visited[MAX][MAX];
int jx, jy;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

queue<pair<int, int>> q;

void solution()
{
	q.push( make_pair(jx,jy) );
	visited[jx][jy] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();


		if (field[y][x] == 0 && (x == 1 || x == C || y == 1 || y == R)) 
		{
			sol = visited[y][x];
			return;
		}

		for (int i = 0; i < 4; i++) 
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny < 1 || nx>C || ny>R) continue;
			if (field[ny][nx] == 1) continue;
			if (visited[ny][nx] == -1) {
				visited[ny][nx] = visited[y][x] + 1;
				field[ny][nx] = field[y][x];
				q.push(make_pair( ny,nx ));
			}
		}
	}
}
void Input()
{
	char s;
	cin >> R >> C;
	memset(visited, -1, sizeof(visited));
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> s;
			if (s == '#')
				field[i][j] = 1;
			else if (s == 'F')
			{
				field[i][j] = 1;
				q.push(make_pair(i, j));
				visited[i][j] = 0;
			}
			else if (s == 'J')
			{
				field[i][j] = 0;
				jy = i;
				jx = j;
			}
			else
				field[i][j] = 0;
		}
	}
}



int main(void) {
	Input();
	solution();
	
	if (sol == 1000000000)
		cout << "IMPOSSIBLE";
	else
		cout << sol;
}


//https://www.acmicpc.net/problem/4179
//우선큐에 넣어야 할 것을 찾아야함
//https://www.acmicpc.net/board/view/31494
//반례 모음
/*
5 5
....F
...J#
....#
....#
...#.
반례에서 4가 나와야 함
*/
