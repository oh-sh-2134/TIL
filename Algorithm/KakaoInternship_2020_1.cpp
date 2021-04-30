#include <string>
#include <vector>
#include <iostream>

using namespace std;


string solution(vector<int> numbers, string hand) {
	string answer = "";
	int right = 4, left = 4, mid;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] && numbers[i] % 3 == 0) {
			answer += "R";
			right = numbers[i] / 3;
		}
		else if (numbers[i] % 3 == 1) {
			answer += "L";
			left = numbers[i] / 3 + 1;
		}
		else {
			int r=0,l=0;
			if (numbers[i] == 0) mid = 8;
			else if (numbers[i] % 3 == 2) mid = numbers[i] / 3 + 5;

			if (right > 4) r = abs(mid - right);
			else r = abs(mid - right-4) + 1;

			if (left > 4) l = abs(mid - left);
			else l = abs(mid - left-4) + 1;

			if (r > l) {
				answer += "L";
				left = mid;
			}
			else if (l > r || hand == "right") {
				answer += "R";
				right = mid;
			}
			else {
				answer += "L";
				left = mid;
			}
		}
	}
	return answer;
}
int abs(int a) {
	return a >= 0 ? a : a * (-1);
}
int main(void) {
	vector<int> v = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
	string s = "right";
	cout << solution(v, s);
}
//https://tech.kakao.com/2020/07/01/2020-internship-test/
//생각보다 어려워서 고민도 많이하고 다른 분들의 풀이도 참조했음
//키패드를 좌표로 생각하고 풀이함
