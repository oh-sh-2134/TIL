#include<iostream>
#include<string>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	string s1, s2;
	cin >> s1 >> s2;
	string s3(max(s1.size(), s2.size()),'0');
	int temp = 0;
	bool carry = false;
	for (int i = 0; i < s3.size(); i++) {
		int temp = carry;
		carry = false;

		if (s1.size() > i) {
			temp += s1[s1.size() - i - 1] - '0';
		}

		if (s2.size() > i) {
			temp += s2[s2.size() - i - 1] - '0';
		}

		if (temp >= 10) {
			carry = true;
			temp -= 10;
		}
		s3[s3.size() - i - 1] = temp + '0';
	}
	if (carry) {
		s3.insert(s3.begin(), '1');
	}
	cout << s3;
}
//https://www.acmicpc.net/problem/10757
//숫자가 커서 정수형 변수로 받을 수 없는 문제이다.
//string으로 받아서 각각의 배열을 덧셈하여 올림 발생시 처리하는 로직으로 품
//어제 풀었던 파보나치4번 문제를 응용 함