#include<iostream>
#define MAX 100001
#define min(a,b) a>b?b:a;
using namespace std;
int dp[MAX];
int main(void) {
	int n, k=1, cnt = 0;
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int p = i;
		if (p - (k + 1)*(k + 1) >= 0) // 제곱으로 나누어지는 가장 큰 수를 찾는 조건문
			k += 1;
		dp[i] = 999999999;
		int c = k;
		while (c > 0) {   
			if (p - c * c >= 0) {
				dp[i] = min(dp[p - c * c] + 1,dp[i]); // 제곱근으로 나누어지는 가장 큰 수부터 1까지 차례로 빼면서 나머지숫자는 dp로 가져와서 비교
				c--;
			} 
		}
	}
	cout << dp[n];
}
//https://www.acmicpc.net/problem/1699
//이전에 틀렸던 문제 중 백준 11052 카드 구매하기 문제랑 비슷하게 풀면 된다고 판단하고 2트만에 통과
//아래에서부터 n까지 각 dp에 가장 작은 횟수들을 유지하고 있으면 됨
