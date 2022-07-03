#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	if (s.length() % 2) {
		answer += s[s.length() / 2];
		return answer;
	}

	answer = s.substr((s.length() / 2) - 1, 2);

	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/12903