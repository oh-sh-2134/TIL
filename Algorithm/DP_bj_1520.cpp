#include<iostream>
#include<queue>
#define MAX 500

using namespace std;
int load[MAX][MAX];
int dp[MAX][MAX];
int N, M;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int max(int a, int b) {
	return a > b ? a : b;
}

int solution() {
	int cnt = 0;
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!(nx > 0 || nx <= N || ny > 0 || ny <= M)) continue;
			if ((ny == M - 1) && (nx == N - 1)) {
				cnt++;
				continue;
			}
			if (load[y][x] > load[ny][nx]) {
				q.push(make_pair(ny, nx));
				dp[ny][nx] = dp[y][x];
			}
		}
	}
	return cnt;
}

void Input() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> load[i][j];
		}
	}
}
int main() {
	int sol;
	Input();
	sol = solution();
	cout << sol;
}
//https://www.acmicpc.net/problem/1520
//제출시 바운더리에러나는 부분 해결필요...
