#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = s;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == ' ') continue;
		else if (answer[i] <= 'Z')answer[i] = answer[i] + n > 'Z' ? answer[i] + n - 26 : answer[i] + n;
		else if (answer[i] <= 'z') answer[i] = answer[i] + n > 'z' ? answer[i] + n - 26 : answer[i] + n;
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12926