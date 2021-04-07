#include<iostream>
#define MAX 500
using namespace std;

int DP[MAX][MAX];
int Triangle[MAX][MAX];
int n;
int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> Triangle[i][j];
		}
	}
	DP[0][0] = Triangle[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) //x축이 0인경우 위의 대각선은 하나밖에 없음
				DP[i][j] = DP[i - 1][j]+Triangle[i][j];
			else // 0이 아닐때는 0과 -1비교하면 됨
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j-1]) + Triangle[i][j];
		}
	}
	int sol = 0;
	for (int i = 0; i < n; i++) {
		if (sol <= DP[n - 1][i]) sol = DP[n - 1][i];
	}
	cout << sol;
}
//https://www.acmicpc.net/problem/1932
//삼각형 라인의 DP에 최댓값을 더해서 유지해나가면 되는 문제
//문제를 y축과 x축으로 봤을때 대각선이 될 수 있는건 위로는 x축이 -1 아래로는 +1 면 됨 
//계산할때는 자신의 y축라인보다 작은 DP에서 x축이 같은 DP와 -1인 DP만 비교하면 됨