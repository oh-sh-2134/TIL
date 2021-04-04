#include<iostream>
#define MAX 1001
using namespace std;

int n;

int DP[MAX];

int tile(int i) {
	if (i == 1) return 1;
	if (i == 2) return 2;
	if (DP[i] != 0) return DP[i]; // 이미 계산 했으면 다시 계산안함
	return DP[i] = (tile(i - 1) + tile(i - 2))%10007;
}
int main(void) {
	cin >> n;
	cout << tile(n);
}
//https://www.acmicpc.net/problem/11726
//dp의 기본문제 타일링