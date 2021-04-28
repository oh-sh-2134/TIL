#include<iostream>

using namespace std;
int k, n;

int Sol(int a, int b) {
	if (b == 1)
		return 1;
	if (a == 0)
		return b;
	return (Sol(a - 1, b) + Sol(a, b - 1));
}

int main() {
	int T, k, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << Sol(k, n) << "\n";
	}
}
//https://www.acmicpc.net/problem/2775
//k층의 n호실에 살려면 k-1층 n호실과 k층 n-1호실의 인원수를 합한 숫자의 사람이 살면됨
//점화식만 잘 찾으면 쉽게품