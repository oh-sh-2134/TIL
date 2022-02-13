#include <string>
#include <vector>

using namespace std;
vector<int> num;
int tar;
int sol;
void dfs(int sum, int n) {
	if ((n - 1) == 0) {
		if (sum + num[n - 1] == tar || sum - num[n - 1] == tar)
			sol++;
		return;
	}

	dfs(sum + num[n - 1], n - 1);
	dfs(sum - num[n - 1], n - 1);
	return;
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	for (auto iter : numbers)
		num.push_back(iter);

	tar = target;
	dfs(0, num.size());
	answer = sol;
	return answer;
}