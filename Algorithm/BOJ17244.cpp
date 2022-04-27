#include <iostream>
#include <queue>
#include<cstring>
#define MAX 51
using namespace std;

int room[MAX][MAX];
int way[MAX][MAX][(1 << 6)];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int cnt;
int n, m;
struct point
{
	int x = 0;
	int y = 0;
};
point startPoint;


void input() {
	cin >> m >> n;
	cnt = 0;
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;

			if (c == 'X')
				room[i][j] = ++cnt;

			else if (c == '#')
				room[i][j] = -1;
			else if (c == 'E')
				room[i][j] = 6;
			else if (c == 'S') {
				startPoint.y = i;
				startPoint.x = j;
				room[i][j] = 0;
			}

			else
				room[i][j] = 0;
		}
	}
}

void bfs() {
	queue < pair < pair<int, int> ,int> >q;
	q.push({ { startPoint.y, startPoint.x },{0} });
	way[startPoint.y][startPoint.x][0] = 1;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int state = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i]; 
			int nx = x + dx[i];

			//범위 체크
			if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;

			//벽일때
			if (room[ny][nx] < 0) continue;
			
			//물건을 모두 집었을때
			if (state == ((1 << cnt) - 1)) {
				//출입구라면
				if (room[ny][nx] == 6) {
					cout << way[y][x][state] << "\n";
					return;
				}
			}



			//물건이 있을때
			if (room[ny][nx]>0) {
				int newState = state | (1 << (room[ny][nx]-1));
				if (way[ny][nx][newState]) continue;
				way[ny][nx][newState] = way[y][x][state] + 1;
				q.push({ {ny, nx}, newState} );
			}
			if (way[ny][nx][state]) continue;
			way[ny][nx][state] = way[y][x][state] + 1;
			q.push({ {ny, nx}, state });
		}
	}
}

void solution() {
	bfs();
}

int main(void) {
	input();
	solution();
}

//https://www.acmicpc.net/problem/17244