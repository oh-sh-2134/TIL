#include <iostream>

using namespace std;

long long n, k;

void input() {
	cin >> n >> k;
}


/*
n*n에서 num보다 작은 숫자의 개수를 구하는 함수
*/
long long findLessNun(long long num) {
	long long cnt = 0;
	for (long long i = 1; i <= n; i++) {
		cnt += min(n, ((long long)num / i));		
		if (i > num) break;
	}
	return cnt;
}

void solution(){
	long long lo = 1, hi = n * n;
	long long sol = 0;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		if (findLessNun(mid)<k) {
			lo = mid + 1;
		}
		else {
			sol = mid;
			hi = mid - 1;
		}
	}
	cout << sol;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/1300