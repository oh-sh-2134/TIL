#include <string>
#include <vector>
#define mod 1000000007
using namespace std;

int solution(int n) {
	vector<int> dp;
	dp.resize(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	int answer = dp[n];
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12900