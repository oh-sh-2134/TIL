#include<iostream>
#include<queue>
#define MAX 1001

using namespace std;

int dp[MAX][MAX];

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for(int j = 1;j <= m; j++){
			dp[i][j] += max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - 1]));
			/* (i, j)가 이동했을때 당시에 (i-1,j),(i,j-1),(i-1,j-1)에 저장되어 있는 dp 중에서
				가장 큰 수만 찾아서 더해가면 되고 추가 배열이 필요없고 기존의 미로에
				덮어씌워가면서 최대값을 만들어 가면 됨
			*/
		}
	}
	
	cout << dp[n][m];

}
//https://www.acmicpc.net/problem/11048
//전체를 이동하며 해당 미로칸이 최대의 값을 가지면 됨 dp이용