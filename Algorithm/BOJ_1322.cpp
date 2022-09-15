#include <iostream>

using namespace std;

long long X, Y, K;

void input() {
	cin >> X >> K;
}

void solution() {
	int pushCnt = 0;
	//long long -> bit : 8byte * 8 = 64
	for (int i = 0; i < 65; i++) {
		//1bit가 아닌 자리의 bit를 더해야 함
		if ((X >> i) & 1) continue;
		if ((K >> pushCnt) & 1) {
			Y |= (1LL << i);
		}
		pushCnt++;
	}
	cout << Y;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/1322