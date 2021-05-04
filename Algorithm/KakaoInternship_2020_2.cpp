#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

string cal(string str, int p, char c) {
	int s = 0 , f = 0;
	int fn, sn, sum;
	string front, back;
	for (int i = p + 1; ; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			s = s * 10 + int(str[i] - '0');
			sn = i;
		}
		else break;
	}
	for (int i = p - 1; ; i--) {
		if (str[i] >= '0' && str[i] <= '9') {
			f = f + int(str[i] - '0')*pow(10 , (p - 1 - i));
			fn = i;
		}
		else break;
	}
	if (c == '+')
		sum = s + f;
	else if (c == '*')
		sum = s * f;
	else
		sum = s - f;
	
	for (int i = 0; i < fn; i++) {
		front += str[i];
	}
	for (int i = sn + 1; i < str.size(); i++) {
		back += str[i];
	}
	return str = front + std::to_string(sum) + back;
}

int max(int a, int b) {
	return a > b ? a : b;
}

long long solution(string expression) {
	long long answer = 0;
	string arr[6] = { "+*-","+-*","-+*","-*+","*+-","*-+" };
	for (int i = 0; i < 6; i++) {
		for (int n = 0; n < 3; n++) {
			for (int j = 1; j < expression.size(); j++) {
				if (expression[j] == arr[i][n]) {
					expression = cal(expression, j, arr[i][n]);
				}
			}
		}
		answer = max(answer, stoi(expression));
	}

	return answer;
}

int main(void) {
	string s = "100-200*300-500+20";
	cout << solution(s);
}
//https://tech.kakao.com/2020/07/01/2020-internship-test/
//0503 cal함수에서 숫자 추출하는 부분을 좀 더 고민해봐야겠음...
//0504 cal함수에서 숫자 추출하고 연산하는 부분까지 했음 앞뒤로 남은 문자열과 함께 다시 합치는 부분  
