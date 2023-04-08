#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	int n = sequence.size();

	int max_sum = 0;
	int end = 0;

	vector<vector<int>> res;
	for (int i = 0; i < n; i++) {

		while (max_sum < k && end < n) {
			max_sum += sequence[end];
			end++;
		}

		if (max_sum == k) {
			res.push_back({ i, end - 1, end - 1 - i });
		}

		max_sum -= sequence[i];
	}

	sort(res.begin(), res.end(), [](vector<int>& a, vector<int>& b) {
		return a[2] < b[2];
	});
	vector<int> answer = { res[0][0], res[0][1] };
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/178870?language=cpp