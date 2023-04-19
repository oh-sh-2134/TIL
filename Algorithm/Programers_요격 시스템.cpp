#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
	int answer = 1;
	sort(targets.begin(), targets.end(), [](vector<int> a, vector<int> b) {return a[1] < b[1]; });
	int min = targets[0][1];
	for (auto target : targets) {
		if (min <= target[0]) {
			min = target[1];
			answer++;
		}
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/181188