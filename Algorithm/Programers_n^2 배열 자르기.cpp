#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;
	for (auto i = left; i <= right; i++) {
		int j = floor(i / n) - i % n;
		j = j < 0 ? 0 : j;
		answer.push_back(i % n + 1 + j);
	}
	return answer;

}
//https://school.programmers.co.kr/learn/courses/30/lessons/87390