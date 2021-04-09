#include<iostream>
#include<string>
#define MAX 1001

using namespace std;
/*
string dp[MAX][10];
int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		if (i == 9) dp[0][9] = "10";
		else dp[0][i] = (i+1) + '0';
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] ='1';
			else {
				string s1=dp[i - 1][j], s2=dp[i][j - 1], s3(max(s1.size(),s2.size()),'0');
				int temp;
				bool carry=false;
				for(int k = 0 ; k< s3.size(); k++){
				
					temp = 0;
					if (carry) temp += 1;
					carry = false;

					if (k<s1.size()) {
						temp += s1[s1.size() - 1 - k] - '0';
					}

					if (k<s2.size()) {
						temp += s2[s2.size() - 1 - k] - '0';
					}
					
					if (temp >= 10) {
						temp -= 10;
						carry = true;
					}
					s3[s3.size() - 1 - k] = temp + '0';
				}
				if (carry) s3.insert(s3.begin(),'1');
				dp[i][j]=s3;
			}
		}
	}
	cout << dp[n-1][9];
}
*/
int dp[MAX][10];

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= 10; i++) {
		dp[1][i] = i; // 1이상이라서 첫번째줄 처리하는 부분
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			if (j == 1) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}
	}
	cout << dp[n][10];
}
//https://www.acmicpc.net/problem/11057
//DP로 각숫자별로 가질 수 있는 오르막수를 저장해놓으면 dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 이 성립
//10007로 나누는 것을 안봐서 큰수받기 문제 처럼 string처리해서
//덧셈을 해야하는 줄 알고 다푼문제를 2시간이나 더 잡고있다가 반례도 없는데 답이 안나와서
//다른사람 코드 참고했는데 이게 뭐람...