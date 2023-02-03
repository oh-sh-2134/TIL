#include <string>
#include <vector>

using namespace std;

bool skipChar[26];

char convert(char s, int idx) {

	while (idx) {
		s++;
		if (s - 'a' >= 26) s = 'a';
		if (skipChar[s - 'a']) continue;
		idx--;
	}
	return s;
}


string solution(string s, string skip, int index) {
	string answer = "";
	for (int i = 0; i < 26; i++) skipChar[i] = false;
	for (auto iter : skip) skipChar[iter - 'a'] = true;
	for (auto iter : s) answer += convert(iter, index);
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/155652