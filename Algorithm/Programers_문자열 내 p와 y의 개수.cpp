#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	int cnt = 0;
	for (auto c : s) {
		if (c == 'y' || c == 'Y')
			cnt++;
		else if (c == 'p' || c == 'P')
			cnt--;
	}
	if (cnt) answer = false;

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12916