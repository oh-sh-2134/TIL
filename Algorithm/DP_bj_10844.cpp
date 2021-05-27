#include<iostream>
# define MAX 100
# define Mod 1000000000

using namespace std;

int n;
int dp[MAX][9];

void Input()
{
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		dp[i][0] = 1;
	}
}

void solution()
{
	for (int i = 1; i < n; i++)
	{
		dp[0][i] = dp[1][i - 1];
		dp[9][i] = dp[8][i - 1];
		for (int j = 1; j < 9; j++)
		{
			dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % Mod;
		}
	}
}
int main(void)
{
	int sol = 0;
	Input();
	solution();
	for (int i = 1; i < 10; i++) {
		sol = (sol + dp[i][n - 1])%Mod;
	}
	cout << sol;
}
//https://www.acmicpc.net/problem/10844
//0526 규칙을 발견해 점화식을 새웠고, 예시는 다 맞지만 제출시 틀림...
//0527 0에대한 케이스 생각을 잘 못했다. 두자리수 이상에서 0을 사용할 수 있는데 숫자가 길어질수록 0에대한 케이스가 많아 질 수 있음, 1가지 케이스로 고정시키면 안됨 -> 정답
