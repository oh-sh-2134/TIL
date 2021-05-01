#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(string expression) {
	long long answer = 0;
	string arr[6] = { "+*-","+-*","-+*","-*+","*+-","*-+" };
	for (int i = 0; i < 6; i++) {
		for (int n = 0; n < 3; n++) {
			for (int j = 1; j < expression.size(); j++) {
				if (expression[j] == arr[i][n]) {

				}
			}
		}
	}

	return answer;
}
string cal(string str, int p) {
	string f, s;
	int fn, sn,sum;
	for (int i = p + 1; ; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			s += str[i];
		}
		else break;
	}
	for (int i = p - 1; ; i--) {
		if (str[i] >= '0' && str[i] <= '9') {
			string tmp = str[i]
			f.insert (0, (string)str[i]);
		}
		else break;
	}
}

int main(void) {
	string s = "100-200*300-500+20";
	cout << solution(s);
}