#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int n = s.length();
	int cnt = 0, i = 0;
	for (int k = 1; k <= n / 2; k++) { // 같을 수 있는 문자열의 총길이
		if (i + k > n) { // 범위가 벗어나버림
			cnt += n - i;
			break;
		}
		// 비교하는 부분 고민
	
	}
	int answer = 0;
	return answer;
}

int main(void) {
	string s = "aabbaccc"; //7
	cout << solution(s);

}
//https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/
//문자열의 길이가 n일때 2/n 보다 크게 잘라야 함