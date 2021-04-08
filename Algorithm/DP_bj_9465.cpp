#include<iostream>
#define MAX 100001
using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int dp[2][MAX];

int main(void) {
	int t; 
	cin>>t;
	while (t-- > 0) {
		int n;
		cin >>n;
		for (int i = 0; i <= 1; i++)
			for (int j = 1; j <= n; j++)
				cin >> dp[i][j];
		
		int topmax = dp[0][1];	
		int bottommax = dp[1][1];
		for (int i = 2; i <= n; i++) {
			dp[0][i] = bottommax + dp[0][i];
			dp[1][i] = topmax + dp[1][i];
			// 대각선으로만 접근할 수 있기때문에 위에는 bottommax와 현제 값을 더한 값을 유지 아래는 반대로
			bottommax = max(bottommax, dp[1][i]);
			topmax = max(topmax, dp[0][i]);
		}	//그리고 bottommax값을 더한 위의 dp와 topmax를 비교해서 큰 수를 topmax로 가져가면됨
		cout<< max(bottommax,topmax) <<"\n";
	}
	return 0;
}
//https://www.acmicpc.net/problem/9465
//dp로 간단하게 풀 수 있는 문제 dp로 받아서 위쪽과 아랫쪽에서의 최댓값을 유지해나가면 됨
//27번줄"\n"안넣어서 몇시간동안 반례를 찾았다...