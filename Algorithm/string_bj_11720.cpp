#include<iostream>
#define MAX 100

using namespace std;
char str[MAX];

int main(void) {
	int n, tmp = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		tmp += str[i] - '0'; // 아스키 코드의 차이를 이용함
	}
	cout << tmp;
}
//https://www.acmicpc.net/problem/11720
//최근 스트링 관련 문제를 조금 풀어보는중..
//준비해야할게 있어서 쉬어가는 날..