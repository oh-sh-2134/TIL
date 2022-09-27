#include <iostream>
#define MAX 1000000000
using namespace std;


long long X, Y, Z;

void input() {
	cin >> X >> Y;
	Z = Y * 100LL / X;
}


bool check(long long mid) {
	long long nY = ((Y+mid) * 100LL / (X+mid));
	return nY > Z;
}

void solution() {
	
	long long l = 0;
	long long r = MAX;
	//�·��� 99�̻��̸� �ٲ��� ����
	if (Z >= 99) {
		cout << -1;
		return;
	}
	while (l + 1 < r) {
		long long mid = (l + r) >> 1;
		//�·��� ���������� ������ �� ����
		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout <<r;
}
int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/1072