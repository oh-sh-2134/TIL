#include<iostream>
#include<algorithm>
#define MAX 301
using namespace std;
int DP[MAX],field[MAX];
int n;


int main(void) {
	cin >> n;
	int cnt = 2;
	for (int i = 0; i < n; i++) {
		cin >> field[i];
	}

	DP[0] = field[0];
	DP[1] = field[0] + field[1];
	DP[2] = field[0] + field[2];
	while (n > cnt ) {
		DP[cnt] = max(DP[cnt - 3] + field[cnt - 1], DP[cnt - 2]) + field[cnt];
		// 4번째 계단에 올라갔을때 가장 높은 케이스를 찾기 위해서 
		// 점프하지 않았을 때와 점프했을 때를 비교하고 높은 점수 + 현제 계단 점수로 DP를 만들어 나감
		cnt++;
	}
	cout << DP[n-1];

}
//https://www.acmicpc.net/problem/2579
//결국에는 현제의 +4에서 최댓값을 가지는 케이스가 가장 높은 점수를 얻는 케이스
//계단이 3개인 케이스까지는 수기 입력하고 4개부터는 while문으로 체크하면 됨