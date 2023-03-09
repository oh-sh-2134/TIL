#include<iostream>
#include<vector>

using namespace std;

int n, d, k, c;
vector<int> duplicationTable;
vector<int> susi;

void input() {
	cin >> n >> d >> k >> c;
	duplicationTable = vector<int>(d+1, 0);
	susi = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> susi[i];
	}
}

void solution() {
	int answer = 0, flag, coupon;
	auto max = [](int a, int b) { return a > b ? a : b; };
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		coupon = 1;
		for (int j = i; j < i + k; j++)
		{
			if (duplicationTable[susi[j%n]] == 1) flag++; 	
			else duplicationTable[susi[j%n]] = 1; 
			if (susi[j%n] == c) coupon = 0; 
		}

		answer = max(answer, k - flag + coupon);
		fill(duplicationTable.begin(), duplicationTable.end(), 0);
	}
	cout << answer;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/2531