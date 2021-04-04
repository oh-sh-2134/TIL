#include<iostream>

using namespace std;


int n;
int recu(int n) {
	if (n==0) return 0;
	if (n == 1) return 1;
	return recu(n - 1) + recu(n - 2);
}

int main(void) {
	cin >> n;
	cout << recu(n);
}

//https://www.acmicpc.net/problem/10870
// 피보나치 수열 문제
// n을 입력받아 1번부터 카운트하며 재귀할 경우 계속 런타임이 발생
// 뒤에서부터 재귀 타는 방법 생각