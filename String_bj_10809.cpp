#include<iostream>
#include<string>

using namespace std;
int arr[26];
int main(void) {
	string s;
	cin >> s;
	for (int i = 0; i < 26; i++) {
		arr[i] = -1; // 배열을 모두 -1로 초기화
	}
	for (int i = 0; i < s.size(); i++) {
		if (arr[s[i] - 'a'] == -1) // 아스키 코드의 차를 이용해 각 배열에 대입
			arr[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
}
//https://www.acmicpc.net/problem/10809
//아스키 코드의 차이를 이용하는 문자열 문제