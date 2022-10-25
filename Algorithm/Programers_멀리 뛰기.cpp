#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
	vector<long long> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] = dp[i] % 1234567;
	}
	long long answer = dp[n - 1];
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12914