#include<iostream>
#include<queue>
#define MAX 1001

using namespace std;

int n, m;
int field[MAX][MAX];
int cnt;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>>q;

bool check() { // 안익은 토마토가 있는지 체크하는 함수
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] == 0) return true;
		}
	}
	return false;
}

int bfs() {
	int size = 0;
	while (!q.empty()) {
		size = q.size();
		for (int j = 0; j < size; j++) { // 하루의 기준은 익은토마토가 주위의 토마토를 익게할 수 있는 경우의 수 인 q.size
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (field[ny][nx] == 0 ) {
					field[ny][nx] = 1;
					q.push(pair<int, int>(ny, nx));
				}
			}
		}
		cnt++;
	}
	if (check()) return -1;
	else return cnt-1;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
		}
	}
	if (!check()) cout << "0";
	else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (field[i][j] == 1) q.push(pair<int, int>(i, j)); // 익은토마토 q에다 넣어둠
			}
		}
		cout << bfs()<<endl;
	}
}
//https://www.acmicpc.net/problem/7576
//3차원 토마토를 이미 풀었기 때문에 쉬웟음