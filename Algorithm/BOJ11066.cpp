#include<iostream>
#include<algorithm>
using namespace std;

int dp[501][501];
int sum[501];
int t, n, c;
int main(void) {
	sum[0] = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		for(int i =1;i<=n;i++){
			cin >> c;
			sum[i] = sum[i - 1] + c;
		}
		for (int k = 1; k < n; k++) {
			int i = 1;
			int j = k + 1;
			for (int a = 0; a < n - k; a++) {
				dp[i][j] = 987654321;
				for (int m = j - k; m <= j - 1; m++) {
					dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j] + sum[j] - sum[i - 1]);
				}
				i++;
				j++;
			}
		}
		cout << dp[1][n] << "\n";
	}
}

//https://melonicedlatte.com/algorithm/2018/03/22/051337.html
//https://www.acmicpc.net/problem/11066