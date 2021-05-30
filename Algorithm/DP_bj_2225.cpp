#include <iostream>
using namespace std;
#define MAX 201
#define Mod 1000000000
int dp[MAX][MAX];
int n, k, i, j;

void Input()
{
	cin >> n >> k;
}

void solution()
{
	for (i = 0; i <= n; i++) dp[1][i] = 1;
	for (i = 0; i <= k; i++) dp[i][0] = 1;

	for (i = 2; i <= k; i++) {
		for (j = 1; j <= n; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % Mod;
		}
	}
}
int main() 
{
	Input();
	solution();
	cout << dp[k][n];
}
//https://www.acmicpc.net/problem/2225
//이차원 배열로 dp[k][n]은 k개를 이용해서 n숫자를 만드는 경우 의미
/*
2개를 더해서 2가 되는 경우의 수를 찾아보면
dp[1][0] + dp[1][2]
dp[1][1] + dp[1][1]
dp[1][2] + dp[1][0]
케이스
dp[k-1][n-0]
dp[k-1][n-1]
dp[k-1][n-2] 의 경우의 수들이 사용 됨
점화식은 dp[k][n] = dp[k-1][n-0] + dp[k-1][n-1] ... + dp[k-1][n-n] 이되고
dp[k-1][0]부터 dp[k-1][n-1]을 모두 더한 것이 dp[k][n-1]에 있음 추가적으로 dp[k-1][n]만 더해주면 됨
*/