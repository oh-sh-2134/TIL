#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

int n;
bool arr[21][21];

int min(int a, int b) {
	return a > b ? b : a;
}

void Input() {
	char c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == 'T') arr[i][j] = true;
		}
	}
}

int solution(int status) {
	int cnt = 0;
	//열
	for (int i = 0; i < n; i++) {
		int front = 0;
		int back = 0;
		//행
		for (int j = 0; j < n; j++) {
			//행이 뒤집힌 케이스
			if (status & (1<<j)){
				if (arr[j][i]) back++;
				else front++;
			}
			//안 뒤집혔을때
			else {
				if (arr[j][i]) front++;
				else back++;
			}
		}
		//앞면이 많으면 뒤집으면 됨
		cnt += min(front, back);
	}
	return cnt;
}

int main(void) {
	Input();
	int cnt = n * n;
	//행이 뒤집어 질 수 있는 모든 케이스를 확인
	for (int i = 0; i < (1 << n) - 1; i++)
		cnt = min(cnt, solution(i));
	cout << cnt;
}