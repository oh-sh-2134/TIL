#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int n, m;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0, 0,-1,1 };

char field[MAX][MAX];
int visited[MAX][MAX] = { 1, };
/* 처음에 dfs로 풀었는데 시간초과;;
void dfs(int y, int x , int c) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!(nx < 0 || nx >= m || ny < 0 || ny >= n)) {
			if (field[ny][nx] == '1') {
				field[ny][nx] = '0';
				if (visited[ny][nx] == 0 || visited[ny][nx] >= (c + 1)) {
					visited[ny][nx] = c + 1;
					dfs(ny, nx , c+1);
					cout << "dfs 1 \n";
					field[ny][nx] = '1';
				}
			}
		}
	}
	return;
}
*/
void bfs() {
	queue<int>q;
	q.push(0);
	q.push(0);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!(nx < 0 || nx >= m || ny < 0 || ny >= n)) { //이동
				if (field[ny][nx] == '1') {
					field[ny][nx] = '0';
					if (visited[ny][nx] == 0) {
						// 1인 경로이고 최단 경로일때 맵을 그리게 했는데 bfs에서는 맵은 필요없고 q가
						// 한바퀴돌때마다 카운트를 체크하는게 깔끔할 듯
						visited[ny][nx] = visited[y][x] + 1;
						q.push(nx);
						q.push(ny);
						field[ny][nx] = '1';
					}
				}
			}
		}
	}
}
int main(void) {
	bool flag = false;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			if (field[i][j] != '1') flag = true;
		}
	}

	if (flag) {
		bfs();
		cout << visited[n-1][m-1];
	}
	else cout << n + m - 1;
}
// https://www.acmicpc.net/problem/2178
// dfs 같은 완전 탐색 기법에서는 지수 시간 복잡도 이기때문에 첫번째 간 곳이 최단 경로가 되지 않을경우
// 어마어마하게 오래 걸릴 수 있지만 bfs 같은 경우에는 첫번째로 도착한 곳이 최단 경로이기 때문에
// 최단 거리를 찾는 문제에서는 bfs로 푸는 것이 맞다는 것을 알게 되었다.
