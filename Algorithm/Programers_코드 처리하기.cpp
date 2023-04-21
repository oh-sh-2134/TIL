#include <string>
#include <vector>
using namespace std;

string solution(string code) {
	string answer = "";
	int mode = 0;
	for (int i = 0; i < code.size(); i++) {
		if (code[i] == '1')
			mode = mode > 0 ? 0 : 1;
		else if (mode == (i & 1))
			answer += code[i];
	}
	if (answer.size() == 0) answer = "EMPTY";
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/181932