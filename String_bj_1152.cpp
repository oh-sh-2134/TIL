#include<iostream>
#include<string>

using namespace std;
string s;

int main(void) {
	int cnt = 0;
	bool flag = true;
	getline(cin, s);

	
	for (int i = 0; i < s.size(); i++) {
		
		if ('A' <= s[i] && s[i] <= 'z') {
			if (flag) {
				cnt++;
				flag = false;
			}
		}
		else
			flag = true;
	}
	cout << cnt;
}
//https://www.acmicpc.net/problem/1152
//처음에는 ' '문자열 체크하는 방식으로 했는데 그러면 공백을 채우는 문자열이 나오면 다 카운팅 됨
//문자열은 대소문자 알파벳과 공백 밖에 없기때문에 알파벳 이외의 문자열이 나오면 플레그를 이용해서 카운팅 함