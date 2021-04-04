#include<iostream>
#include<queue>

using namespace std;

int dx[6] = { 1,-1,0,0,0,0, };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int arry[101][101][101];
int cnt;
int m, n, h;

queue<int> qx;
queue<int> qy;
queue<int> qz;
bool check() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arry[i][j][k] == 0) return true;
			}
		}
	}
	return false;
}
int bfs() {
	
	while (!qx.empty()) {
		int size = qx.size();
		for (int j = 0; j<size; j++) {
			for (int i = 0; i < 6; i++) {
				int nx = qx.front() + dx[i];
				int ny = qy.front() + dy[i];
				int nz = qz.front() + dz[i];
				if (!(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)) {
					if (arry[nz][ny][nx] == 0) {
						qx.push(nx);
						qy.push(ny);
						qz.push(nz);
						arry[nz][ny][nx] = 1;
					}
				}
			}
			qx.pop();
			qy.pop();
			qz.pop();
		}
		if(!qx.empty()) cnt++; // 에초에 토마토가 모두 익어 있을 경우
	}
	if (check()) 	return -1;
	return cnt;

}

int main(void) {
	
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arry[i][j][k];
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arry[i][j][k] == 1) {
					qx.push(k);
					qy.push(j);
					qz.push(i);
				}
			}
		}
	}

	cout << bfs();
}
//https://www.acmicpc.net/problem/7569
//queue를 이용한 bfs로 풀었음
// xyz축 큐를 각각 만들어서 익은 토마토를 먼저 큐에 넣고
// 익은 토마토 기준으로 xyz축의 익지 않은 토마토를 체크 하는 방식
// check()함수를 이용해서 모두 익을 수 없는 경우를 확인