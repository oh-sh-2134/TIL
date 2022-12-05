#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int findPalindrome(string s, int left, int right) {

	while (left >= 0 && right < s.size()) {
		if (s[left] != s[right]) {
			break;
		}
		left--;
		right++;
	}
	return right - left - 1;
}

int solution(string s)
{
	int answer = 0;
	for (int i = 0; i < s.size(); i++) {
		answer = max(answer, findPalindrome(s, i, i + 1));
		answer = max(answer, findPalindrome(s, i, i));
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12904