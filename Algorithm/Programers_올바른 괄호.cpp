#include<string>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	int cnt = 0;
	for (auto iter : s) {
		if (iter == '(') {
			cnt++;
		}
		else {
			cnt--;
		}
		//열기 전에 닫기가 나온 케이스
		if (cnt < 0) {
			return false;
		}
	}
	//열린 상태로 끝나는 케이스
	if (cnt)
		return false;

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12909