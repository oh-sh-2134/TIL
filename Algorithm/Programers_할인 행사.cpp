#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> map;
bool check() {
	for (auto &iter : map) {
		if (iter.second)
			return false;
	}
	return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;

	for (int i = 0; i < want.size(); i++)
		map[want[i]] = number[i];

	for (int i = 0; i < discount.size(); i++) {
		map[discount[i]]--;
		if (i < 10) continue;
		if (map.find(discount[i - 10]) != map.end()) {
			map[discount[i - 10]]++;
		}
		if (check())
			answer++;

	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/131127