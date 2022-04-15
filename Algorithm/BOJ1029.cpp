#include<iostream>

using namespace std;

int N;
int dp[15][10][(1 << 15)];
int arr[15][15];
int maxArtist;

int max(int a, int b) {
	return a > b ? a : b;
}

void input() {
	cin >> N;
	char n;
	for (int i = 0; i< N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			arr[i][j] = n - '0';
		}
	}
}

int dfs(int own, int price,int state) {
	int &cnt = dp[own][price][state];

	if (state == (1 << N) - 1) return 0;

	if (cnt) return cnt;

	for (int i = 0; i < N; i++) {
		if (price > arr[own][i]) continue;
		if (state&(1 << i)) continue;
		cnt = max(cnt, dfs(i, arr[own][i], state | (1 << i)) + 1);
			
	}
	return cnt;
}

void solution() {
	cout << dfs(0,0,1)+1;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	solution();
}
//https://www.acmicpc.net/problem/1029