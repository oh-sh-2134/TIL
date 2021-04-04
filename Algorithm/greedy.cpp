#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int main() {
	freopen("text.txt", "r", stdin);
	int N,sum,sol=0;
	long long K;
	cin >> N;
	cin >> K;
	vector<int> table(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> table[i];
	}
	for (int i = N - 1; i > -1; i--) {
		sum = K / table[i];
		sol += sum;
		K = K - table[i] * sum;
		if (K == 0) {
			break;
		}
	}
	cout << sol;

}
//https://www.acmicpc.net/problem/11047