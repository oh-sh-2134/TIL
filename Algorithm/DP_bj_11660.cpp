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
		cin >> y1 >> x1 >> y2 >> x2;
		xy.push_back(make_pair(make_pair(y1, x1),(make_pair(y2,x2))));
	}
}

void make_dp() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
		}
	}
	return;
}

int main() 
{
	Input();
	make_dp();
	for (int i = 0; i < M; i++) {
		int y1 = xy[i].first.first;
		int x1 = xy[i].first.second;
		int y2 = xy[i].second.first;
		int x2 = xy[i].second.second;
		int sol = dp[y2][x2] - dp[y2][x1 - 1] - dp[y1 - 1][x2] + dp[y1 - 1][x1 - 1];
		cout << sol<<"\n";
	}
}
//https://www.acmicpc.net/problem/11660
//0524 ¹æ¹ýÀº Ã£Àºµí ÇÔ
