#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 0;
	int enterPoint = -30001;
	sort(routes.begin(), routes.end(),
		[](vector<int> a, vector<int> b)->bool {
		return a[1] < b[1];
	});
	for (auto &iter : routes) {
		if (enterPoint < iter[0]) {
			answer++;
			enterPoint = iter[1];
		}
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/42884