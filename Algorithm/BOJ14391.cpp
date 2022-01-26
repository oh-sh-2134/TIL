#include<iostream>
#include<string>
#define MAX 4

using namespace std;

int n, m;
int arr[MAX][MAX];

int max(int a, int b) {
	return a > b ? a : b;
}

void Input() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
}

void solution() {
	int ans = 0;
	for (int s = 0; s < (1 << (n*m)); s++) {
		int sum = 0;

		//가로
		for (int i = 0; i < n; i++) {

			int now = 0;
			for (int j = 0; j < m; j++) {

				int k = i * m + j;
				
				//가로인경우
				if ((s&(1 << k)) == 0) {
					now = now * 10 + arr[i][j];
				}
				else {
					sum += now;
					now = 0;
				}
			}
			sum += now;
		}

		//세로
		for (int j = 0; j < m; j++) {

			int now = 0;
			for (int i = 0; i < n; i++) {
				int k = i * m + j;

				//세로인경우
				if ((s&(1 << k))!=0) {
					now = now * 10 + arr[i][j];
				}

				else {
					sum += now;
					now = 0;
				}


			}
			sum += now;
		}
		ans = max(sum, ans);
	}
	cout << ans;
}

int main(void) {
	Input();
	solution();
}
//https://www.acmicpc.net/problem/14391