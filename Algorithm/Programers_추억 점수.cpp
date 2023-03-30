#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
	vector<int> answer;
	unordered_map<string, int> yearningMap;
	for (int i = 0; i < name.size(); i++)
		yearningMap[name[i]] = yearning[i];

	for (auto poto : photo) {
		int yearningPoint = 0;
		for (auto person : poto) {
			yearningPoint += yearningMap[person];
		}
		answer.push_back(yearningPoint);
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/176963