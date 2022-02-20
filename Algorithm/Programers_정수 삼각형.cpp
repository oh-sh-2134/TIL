#include <string>
#include <vector>

using namespace std;
int dp[501][501];
int maxIdx;
int n, m;

int max(int a, int b) {
	return a > b ? a : b;
}


int solution(vector<vector<int>> triangle) {
	n = triangle.size();
	m = triangle[n - 1].size();
	int maxIdx = 0;
	if (triangle.size() == 1) return triangle[0][0];

	dp[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
			maxIdx = max(maxIdx, dp[i][j]);
		}
	}

	int answer = maxIdx;
	return answer;
}