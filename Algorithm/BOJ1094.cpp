#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

#define MAX 987654321
using namespace std;
int N, W[16][16];

int dp[16][1 << 16];

int TSP(int current, int visited) {
	int &ret = dp[current][visited];
	if (ret != -1)
		return ret;

	if (visited == (1 << N) - 1) {

		if (W[current][0] != 0)
			return W[current][0];

		return MAX;
	}
	ret = MAX;
	for (int i = 0; i < N; ++i) {

		if (visited & (1 << i) || W[current][i] == 0)
			continue;
		ret = min(ret, TSP(i, visited | (1 << i)) + W[current][i]);
	}
	return ret;
}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> W[i][j];
	}
	memset(dp, -1, sizeof(dp));
	cout << TSP(0, 1) << '\n';
}

//https://www.acmicpc.net/problem/2098
//dp, 백트래킹, 비트마스킹 사용