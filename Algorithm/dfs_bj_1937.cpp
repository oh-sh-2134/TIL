#include<iostream>

#define MAX 501
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int field[MAX][MAX];
int dp[MAX][MAX];
int n;
int maxcnt;
int ch(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
int dfs(int y, int x) {

	if (dp[y][x] != 0) return dp[y][x]; //dp에 저정되있는 값이 있는경우
	dp[y][x]=1; // 방문을 재방문을 하지 않게하기 위함

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!(nx < 0 || nx >= n || ny < 0 || ny >= n)) {
			if (field[y][x] < field[ny][nx]) {
				dp[y][x] = ch(dfs(ny, nx) + 1, dp[y][x]); //두번 계산하지 않게 하기위해 dp에 저장된 값으로 계산
			}
		}
	}
	return dp[y][x];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maxcnt = ch(maxcnt , dfs(i, j));
		}
	}
	cout << maxcnt;
}
//https://www.acmicpc.net/problem/1937
// dfs로 안풀려서 dp까지 공부했는데 이전에 푼문제에서 나도모르게 dp개념을 사용하고 있었다;;