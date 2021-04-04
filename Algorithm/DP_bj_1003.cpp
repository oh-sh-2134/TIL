#include<iostream>
#define MAX 41

int cnt0, cnt1;
int dp[MAX][1];
using namespace std;

void pabo(int i) {
	dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
	dp[i][1] = dp[i - 1][1] + dp[i - 2][1];	
	return;
}

int main(void) {
	int n;
	cin >> n;
	dp[0][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i < MAX; i++) {
		pabo(i);
	}
	for (int i = 0; i < n; i++) {
		int j;
		cin >> j;
		cout << dp[j][0] << " " << dp[j][1] << "\n";
	}
}
//https://www.acmicpc.net/problem/1003
//파보니치문제 쉬어가는날..