#include<iostream>
#define MAX 1000

using namespace std;

int dp[MAX];
int box[MAX];
int n;

int max(int a, int b)
{
	return a > b ? a : b;
}

void Input() 
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> box[i];
	}
}

int solution()
{
	int sol = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (box[i] > box[j])
				dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
		sol = max(dp[i], sol);
	}
	return sol;
}
int main(void) 
{
	int sol;
	Input();
	sol = solution();
	cout << sol;
}
//https://www.acmicpc.net/problem/1965
//0529 비슷한 문제 복습