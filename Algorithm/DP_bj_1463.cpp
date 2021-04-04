#include<iostream>
#include<algorithm>
#define MAX 1000001

using namespace std;
int DP[MAX];

int main() {
	int n;
	cin >> n;
	DP[1] = 0;
	
	for (int cnt = 2; cnt <= n; cnt++) {
		DP[cnt] = DP[cnt - 1] + 1;
		if (cnt % 2 == 0) {
			DP[cnt] = min(DP[cnt / 2]+1, DP[cnt]);
			//cnt-1 번의 케이스보다 cnt/2번째에서 + 1한 경우의 수를 비교해주어야함
			//2나 3으로 나누더라도 1을 빼야 최솟값이 되는 케이스가 있음
			//571을 예로들면
			//571 - 570 - 190 - 95 - 94 - 47 - 13 - 12 - 4 - 2 - 1
			//571 - 570 - 190 - 189 - 63 - 21 - 7 - 6 - 3 - 1
			//반례 (질문 게시판 출처)642, 643 , 734, 740, 842
		}
		if (cnt % 3 == 0) {
			DP[cnt] = min(DP[cnt / 3]+1, DP[cnt]);
		}
	
	}
	cout << DP[n];
}
//https://www.acmicpc.net/problem/1463
// 위의 케이스 때문에 왜 틀린지도 모르고 한참 고민하다 인터넷의 도움을 받음
// 너무나 어렵고;;