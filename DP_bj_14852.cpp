#include<iostream>
#define MAX 1000001

using namespace std;

long long int DP[MAX][2];
int n;

long long int tiling(int x) {
	DP[0][0] = 1;
	DP[1][0] = 2;
	DP[2][0] = 7;
	for (int i = 3; i <= x; i++) {
		DP[i][1] = (DP[i - 3][0] + DP[i - 1][1]) % 1000000007;
		DP[i][0] = (3*DP[i-2][0] + 2*DP[i-1][0] + 2*DP[i][1]) % 1000000007;
	}
	return DP[x][0];
}

int main(void) {
	cin >> n;
	cout << tiling(n);
}
//https://www.acmicpc.net/problem/14852
//도저히 못풀겠어서 인터넷을 알아보면서 풀었는데
//14번라인의 DP[i - 3][0] + DP[i - 1][1]이 이해가 안가는데 설명해 놓은
//사람이 없어서 결국 혼자 이해하고 다른사람들을 위해 직접 설명을 남겼다.
//https://www.acmicpc.net/board/view/43033 링크