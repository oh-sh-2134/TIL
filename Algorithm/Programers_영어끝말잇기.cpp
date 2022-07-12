#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer = { 0,0 };

	int totalCnt = 1;
	int cnt = 0;
	char lastChar = ' ';
	unordered_set<string> s;

	for (auto iter : words) {

		//끝말잇기 한사이클 돌았을때
		if (cnt == n) {
			cnt = 0;
			totalCnt++;
		}
		cnt++;

		//이어 받을 글자가 없을때
		if (lastChar == ' ') {
			lastChar = iter[iter.size() - 1];
			s.insert(iter);
			continue;
		}

		//앞사람의 마지막 알파벳과 동일하지 않은 경우
		if (lastChar != iter[0]) {
			answer.clear();
			break;
		}

		//말했던 것을 말할경우
		if (s.find(iter) != s.end()) {
			answer.clear();
			break;
		}

		s.insert(iter);

		lastChar = iter[iter.size() - 1];

	}

	//끝까지 다 돌지 못했을때
	if (answer.size() == 0) {
		answer.push_back(cnt);
		answer.push_back(totalCnt);
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12981
