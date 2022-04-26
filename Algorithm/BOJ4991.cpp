#include <iostream>
#include <queue>
#include<cstring>
#define MAX 21
using namespace std;

int room[MAX][MAX];
int cleanCnt[MAX][MAX][(1 << 11)];
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

void bfs() {
	queue < pair < pair<int, int> ,int> >q;
	q.push({ { startPoint.y, startPoint.x },{0} });
	cleanCnt[startPoint.y][startPoint.x][0] = 1;
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

			if (room[ny][nx] < 0) continue;
			
			//더러운 곳일때
			if (room[ny][nx]>0) {
				int newState = state | (1 << (room[ny][nx]-1));

				//더러운곳이 없다면
				if (newState == ((1 << cnt) - 1)) {
					cout<< cleanCnt[y][x][state]<<"\n";
					return;					
				}

				if (cleanCnt[ny][nx][newState]) continue;
				cleanCnt[ny][nx][newState] = cleanCnt[y][x][state] + 1;
				q.push({ {ny, nx}, newState} );
			}
			if (cleanCnt[ny][nx][state]) continue;
			cleanCnt[ny][nx][state] = cleanCnt[y][x][state] + 1;
			q.push({ {ny, nx}, state });
		}
	}
	
	
	cout << -1 << "\n";
}

void solution() {
	while (true) {
		cin >> m >> n;
		if (n == 0 && m == 0) break;
		cnt = 0;
		memset(cleanCnt, 0, sizeof(cleanCnt));
		memset(room, 0, sizeof(room));
		char c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> c;
				
				if (c == '*')
					room[i][j] = ++cnt;

				else if (c == 'x')
					room[i][j] = -1;

				else if (c == 'o') {
					startPoint.y = i;
					startPoint.x = j;
					room[i][j] = 0;
				}
				else
					room[i][j] = 0;
			}
		}
		bfs();
	}
}

int main(void) {
	solution();
}

//https://www.acmicpc.net/problem/4991
