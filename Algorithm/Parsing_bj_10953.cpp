#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int a = s[0] - '0';
		int b = s[2] - '0';
		cout << a + b << '\n';
	}
	return 0;
}
//https://www.acmicpc.net/problem/10953
//10이하로만 받기때문에 스트링으로 받아서 첫번째와 세번째 인덱스만 더해주면됨
//회사에서 파싱프로그램 만드는 김에 한번해봤음