#include<iostream>
#define MAX 10001

using namespace std;

int coin[101];
int dp[MAX];
int n, k;

int min(int a, int b) {
	return a < b ? a : b;
}

int main(void) {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		dp[i] = 10002;
	}
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]]+1);
		}
	}
	if(dp[k]==10002) cout << -1;
	else cout << dp[k];
}
//https://www.acmicpc.net/problem/2294
//가진 코인들로 조합할 수 있는 수를 중 최소값을 구해나가면 되는 문제