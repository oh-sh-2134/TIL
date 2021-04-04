#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int count = n;
	while (n > 0) {
		string input;
		cin >> input;

		bool alphabet[26] = { false };
		bool flag = true;
		for (int i = 0; i < input.length(); i++) {
			int idx = input[i] - 'a';
			if (!alphabet[idx]) { //방문안했을시 
				alphabet[idx] = true; //방문처리
			}

			else if (alphabet[idx] && (input[i] != input[i - 1])) { //그룹단어가 아니면
				count -= 1; break; //빼주면됨
			}
		}
		n--;
	}
	cout << count;

	return 0;
}
//https://www.acmicpc.net/problem/1316
//알파벳 사이즈만큼의 배열을 만들고 알파벳에 따라 배열에 방문처리를하고
//연속되지 않은 알파벳이 오면 방문했는지 체크해서 방문 했으면 문자열의 갯수에서 하나씩 빼주면됨