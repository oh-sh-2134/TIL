#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = 0;
	int n = s.length();
	int cnt = 0, i = 0;
	for (int k = 1; k <= n / 2; k++) { // 압축할 수 있는 길이
		while (i < n) {
			int equals = 0, next = 0;
			if (i + k > n) { // 범위가 벗어나버림
				cnt += n - i;
				break;
			}
			for (int j = i + k; j < n; j += k) {
				int t;
				for (t = 0; t < k; t++) {	
					if (s[i + t] != s[j + t])break;
				}
				if (t == k) equals++;
				else {
					next = j; break;
				}
			}
			if (equals) {
				if (equals + 1 <= 9)cnt += k + 1;
				else if (equals + 1 <= 99)cnt += k + 2;
				else if (equals + 1 <= 999)cnt += k + 3;
				else  cnt += k + 4;
			}
			else cnt += k;
			if (next == 0)break;
			i = next;

		}
		if (cnt < answer) answer = cnt;
	}
	return answer;
}

int main(void) {
	string s = "aabbaccc"; //7
	cout << solution(s);

}
//https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/
//문자열의 길이가 n일때 2/n 보다 크게 잘라야 함
