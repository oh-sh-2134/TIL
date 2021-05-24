#include<iostream>
#include<vector>
#define MAX 1025
using namespace std;

int N, M;
int arr[MAX][MAX];
int dp[MAX][MAX];
vector<pair<pair<int, int>, pair<int, int>>> xy;

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	int x1, x2, y1, y2;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		xy.push_back(make_pair(make_pair(y1, x1),(make_pair(y2,x2))));
	}
}

void make_dp(int y, int x) {
	if (dp[y][x]) return;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (dp[i][j]) continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
		}
	}
	return;
}

int main() 
{
	Input();
	for (int i = 0; i < M; i++) {
		int y1 = xy.front().first.first;
		int x1 = xy.front().first.second;
		int y2 = xy.front().second.first;
		int x2 = xy.front().second.second;
		make_dp(y2, x2);
		int sol = dp[y2][x2] - dp[y2][x1 - 1] - dp[y1 - 1][x2] + dp[y1 - 1][x1 - 1];
		cout << sol;
	}
}
//https://www.acmicpc.net/problem/11660
//0524 방법은 찾은듯 함