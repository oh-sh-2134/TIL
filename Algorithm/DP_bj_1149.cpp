#include<iostream>
#define MAX 1000
#define R 0
#define G 1
#define B 2

using namespace std;
int street[3][1000];
int dp[3][1000];

int min(int a,int  b) {
	return a > b ? b : a;
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> street[j][i];
		}
	}
	for (int i = 0; i < 3; i++) dp[i][0] = street[i][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == R) //R일때는 이전 DP의 min(G,B)을 구하면 됨
				dp[R][i] = min(dp[G][i - 1], dp[B][i - 1]) + street[R][i];
			else if(j == G) //G일때는 이전 DP의 min(R,B)을 구하면 됨
				dp[G][i] = min(dp[R][i - 1], dp[B][i - 1]) + street[G][i];
			else //B일때는 이전 DP의 min(R,G)을 구하면 됨
				dp[B][i] = min(dp[R][i - 1], dp[G][i - 1]) + street[B][i];
		}
	}
	cout << min(min(dp[R][n - 1], dp[G][n - 1]), dp[B][n - 1]); //마지막 거리에서 최솟값을 가지는 DP가 solution
}
//https://www.acmicpc.net/problem/1149
//DP 이용, 색이 중복되지 않은 이전 DP중 최솟값과 현제 비용을 더해가서 마지막에 3개의 배열중 가장 적은 값이 최솟값이 됨