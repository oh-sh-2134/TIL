#include<iostream>
#define MAX 51
using namespace std;

int n, m;
int r, c, d;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int cnt=1;
int field[MAX][MAX];
int flag=0;

void dfs(int y, int x, int p) {
	if (field[y][x] == 1) return; //벽일경우 그냥돌아감
	if (field[y][x] == 0) { // 방문 안했을시 방문처리
		field[y][x] = 2;
		cnt++;
	}
	int k = p;
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		k = (k + 3) % 4; // 왼쪽으로 
		ny = y + dy[k];
		nx = x + dx[k];
		if (field[ny][nx] == 0){ // 방문 하지 않았을시 이동
			dfs(ny, nx, k);
			return;
		}
	}
	ny = y + dy[(k + 2) % 4]; // 방향을 바꾸지 않고 후진
	nx = x + dx[(k + 2) % 4];
	dfs(ny, nx, k);

	return;
}

int main(void) {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
		}
	}
	field[r][c] = 2;
	dfs(r, c, d);
	cout << cnt;
}
//https://www.acmicpc.net/problem/14503
// 재귀문제이면서 dfs 문제임 벽과 방문처리를 같다고 생각하면 안되는게 핵심인거 같음
// 방문지역을 후진할 순 있지만 벽으로 후진은 못함