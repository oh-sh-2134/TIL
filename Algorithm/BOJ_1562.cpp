#include<iostream>

#define MAX 101
#define numMax 10
#define MOD 1000000000
using namespace std;

int n;

long long dp[MAX][numMax][1 << 10];
void Input() {
	cin >> n;
}

void solution() {
	for (int i = 1; i <= 9; i++) {
		dp[1][i][1 << i] = 1;
	}
	

	for (int k = 2; k <= n; k++) {
		for (int i = 0; i <= 9; i++) {
			for (int bit = 0; bit < (1 << 10); bit++) {

				// k의 i번째 bit를 on 시킨다
				
				// n자리 + i로 끝나고 + 기존 k 상태(여태 사용한 숫자의 모음)에서 숫자 i를 추가하는 경우는
				// n-1자리 + i-1 or i+1로 끝나고 + 기존 상태의 값(숫자 i를 추가하지 않음) 을 더해줘야 한다
				if (i == 0) {
					dp[k][i][bit|(1<<i)] += dp[k - 1][i+1][bit] % MOD;
				}
				else if (i == 9) {
					dp[k][i][bit|(1<<i)] += dp[k - 1][i-1][bit] % MOD;
				}
				else {
					dp[k][i][bit|(1<<i)] += (dp[k - 1][i - 1][bit] + dp[k - 1][i + 1][bit]) % MOD;
				}
			}


		}
	}

	long long cnt = 0;
	for (int i = 0; i <= 9; i++) {
		cnt =(cnt + dp[n][i][(1 << 10) -1]) % MOD;
	}
	cout << cnt;
}

int main(void) {
	Input();
	solution();
}
//https://www.acmicpc.net/problem/1562