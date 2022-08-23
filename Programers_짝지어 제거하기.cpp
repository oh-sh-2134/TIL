#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> dump;
	//문자열이 비어있거나 홀수일 경우
	if (s.empty() || (s.length() & 1))
		return answer;


	for (auto iter : s) {
		if (dump.empty() || dump.top() != iter) {
			dump.push(iter);
		}
		else {
			dump.pop();
		}
	}

	//모두 비어 있다면
	if (dump.empty()) {
		answer = 1;
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12973#