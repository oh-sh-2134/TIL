#include <string>
#include <vector>
#include <iostream>
using namespace std;

string cal(string str, int p, char c) {
	string f, s;
	int fn, sn, sum;
	for (int i = p + 1; ; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			string tmp;
			tmp[0] = str[i];
			s.append(tmp);
			sn = i;
		}
		else break;
	}
	for (int i = p - 1; ; i--) {
		if (str[i] >= '0' && str[i] <= '9') {
			string tmp;
			tmp[0] = str[i];
			f.insert(0, tmp);
			fn = i;
		}
		else break;
	}
	if (c == '+')
		sum = stoi(s) + stoi(f);
	else if (c == '*')
		sum = stoi(s) * stoi(f);
	else
		sum = stoi(s) - stoi(f);
	s.clear();
	f.clear();
	for (int i = 0; i < fn; i++) {
		f += str[i];
	}
	for (int i = sn + 1; i < str.size(); i++) {
		s += str[i];
	}
	return str = f + std::to_string(sum) + s;
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
//0503cal함수에서 숫자 추출하는 부분을 좀 더 고민해봐야겠음...
