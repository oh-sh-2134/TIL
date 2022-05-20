#include<iostream>
#include<algorithm>
using namespace std;

int chess[51][51];

int N, M;
int minIdx = 10004;

void input() {
	char c;
	cin >> N >> M;

	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) {
			cin >> c;
			//검정
			if (c == 'B') { 
				chess[i][j] = 0;
				continue;
			};
			//흰색
			chess[i][j] = 1;
		}
	}
}
int check(int x, int y)
{
	int cnt1 = 0;
	int cnt2 = 0;

	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			//흰색 시작
			if ((i + j) % 2 == chess[i][j]) 
				cnt1++; 
			//검정 시작
			if ((i + j + 1) % 2 == chess[i][j]) 
				cnt2++; 
		}
	}

	return min(cnt1, cnt2); 
}

void solution() {
	for (int i = 0; i <= N - 8; i++) 
		for (int j = 0; j <= M - 8; j++) 
			if (minIdx > check(i, j)) 
				minIdx = check(i, j); 
		
	cout << minIdx;
}

int main()
{
	input();
	solution();
}
//https://www.acmicpc.net/problem/1018