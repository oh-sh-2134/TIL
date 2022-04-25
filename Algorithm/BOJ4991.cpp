#include <iostream>
#include <queue>
#define MAX 20
using namespace std;

char room[MAX][MAX];
int cleanCnt[20][20][(1 << 9)];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
char cnt;
int n, m;
struct point
{
	int x = 0;
	int y = 0;
};
point startPoint;

int min(int a, int b) { return a > b ? b : a; }

void bfs() {
	int minDist = 987654321;
	queue < pair < pair<int, int>, pair<int, int>> >q;
	q.push({ { startPoint.y, startPoint.x },{0,0} });
	cleanCnt[startPoint.y][startPoint.x][0] = 0;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second.first;
		int state = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			//범위 체크
			if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;

			//더러운 곳일때
			if (room[ny][nx] >= '0' && room[ny][nx] <= '9') {
				int newState = state | (1 << (room[ny][nx] - '0'));
				if (newState == ((1 << (cnt - '0' + 1)) - 1)) {
					minDist = min(minDist, cleanCnt[y][x][state] + 1);
					continue;
				}
				if (cleanCnt[ny][nx][newState] < cleanCnt[y][x][state] + 1) continue;

				q.push({ {ny, nx},{ cleanCnt[y][x][state] + 1, newState} });
			}
			if (cleanCnt[ny][nx][state] < cleanCnt[y][x][state] + 1) continue;
			q.push({ {ny, nx},{ cleanCnt[y][x][state] + 1, state} });
		}
	}
	if (minDist == 987654321)
		cout << -1;
	else
		cout << minDist;
}

void solution() {
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		//*는 총 10개까지기 때문에 *을 숫자로 마킹하여 모두 방문했을때 상태의 최솟값을 찾아내면 됨
		cnt = '0';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> room[i][j];
				if (room[i][j] == '*') {
					room[i][j] = cnt;
					cnt += 1;
				}
				else if (room[i][j] == 'o') {
					startPoint.y = i;
					startPoint.x = j;
				}
			}
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				for (int b = 0; b < (1 << 9); b++) {
					cleanCnt[i][j][b] = 987654321;
				}
			}
		}
	

		bfs();
	}
}

int main(void) {
	solution();
}

//https://www.acmicpc.net/problem/4991