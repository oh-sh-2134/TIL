#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
	int cnt = k;
	int maxPos = 0;
	int start = 0;
	string answer = "";
	while (cnt>0) {
		int frontMax = 0;
		int cnt2 = cnt;
		if (answer.length() + cnt == number.length()) break;
		//앞에서 가장 큰수를 찾는다
		for (int i = start; cnt2>=0; cnt2--,i++) {
			if (frontMax<int(number[i])) {
				frontMax = int(number[i]);
				maxPos = i;
			}			
		}
		cnt -= (maxPos - start);
		answer += number[maxPos];
		if (cnt == 0 && (number.length() - answer.length() != k)) answer += number.substr(maxPos + 1);
		start = maxPos+1;
	}
	return answer;
}

int main(void) {
	string s = "654321";
	solution(s, 5);
}
//https://programmers.co.kr/learn/courses/30/lessons/42883