#include <string>
#include <vector>
#include <iostream>
using namespace std;

int char_to_int(int num, char c) {
	return num = num * 10 + (c - '0');
}

int AppendNum(int nums, int num) {
	return nums = nums * 10 + num;
}

int solution(string s) {
	int answer = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			answer = char_to_int(answer,s[i]);
		}
		if (s[i] == 'z') {
			answer = AppendNum(answer, 0);
			i += 3;
		}
		else if (s[i] == 'o') {
			answer = AppendNum(answer, 1);
			i += 2;
		}
		else if (s[i] == 't') {
			if (s[i + 1] == 'w') {
				answer = AppendNum(answer, 2);
				i += 2;
			}
			else if (s[i + 1] == 'h') {
				answer = AppendNum(answer, 3);
				i += 4;
			}
		}
		else if (s[i] == 'f') {
			if (s[i + 1] == 'o') {
				answer = AppendNum(answer, 4);
				i += 3;
			}
			else if (s[i + 1] == 'i') {
				answer = AppendNum(answer, 5);
				i += 3;
			}
		}
		else if (s[i] == 's') {
			if (s[i + 1] == 'i') {
				answer = AppendNum(answer, 6);
				i += 2;
			}
			else if (s[i + 1] == 'e') {
				answer = AppendNum(answer, 7);
				i += 4;
			}
		}
		else if (s[i] == 'e') {
			answer = AppendNum(answer, 8);
			i += 4;
		}
		else if (s[i] == 'n') {
			answer = AppendNum(answer, 9);
			i += 3;
		}
	}
	return answer;
}
int main(void) {
	string s = "1023456789"; //1478
	cout << solution(s);
}