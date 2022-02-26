#include <string>
#include <vector>

using namespace std;
int max(int a, int b) {
	return a > b ? a : b;
}
int solution(vector<int> money) {
	vector<int> dp1(money.size(), 0);
	vector<int> dp2(money.size(), 0);
	dp1[0] = money[0];
	dp1[1] = money[0];
	dp2[1] = money[1];
	for (int i = 2; i < dp1.size() - 1; i++) {
		dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
	}
	for (int i = 2; i < dp1.size(); i++) {
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
	}

	int answer = max(dp1[dp1.size() - 2], dp2[dp2.size() - 1]);
	return answer;
}