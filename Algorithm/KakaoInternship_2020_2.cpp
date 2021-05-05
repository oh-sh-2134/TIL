#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int abs(int a) {
	return a >= 0 ? a : a * (-1);
}
string cal(string str, int p, char c) { // str : 식 / p : 연산자 위치 / c : 연산자
	int s = 0 , f = 0; // f : 연산자의 앞 숫자 / s : 연산자의 뒷 숫자 
	int fn, sn, sum; 
	string front, back; 
	bool flag=false;
	for (int i = p + 1; ; i++) {
		if (str[p+1] == '-' && !flag) { // 뒷숫자의 부호 체크
			flag = true;
			continue;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			s = s * 10 + int(str[i] - '0'); //string -> int
			sn = i;
		}
		else {
			if (flag)
				f *= (-1);
			break;
		}
	}
	flag = false;
	for (int i = p - 1; i>=0 ; i--) {
		if (str[i] >= '0' && str[i] <= '9') {
			f = f + long long(str[i] - '0')*pow(10 , (p - 1 - i)); //stirng -> int
			fn = i;
		}
		else if (str[i] == '-') { //앞 숫자의 부호 체크
			if (i == 0) { // - 부호의 위치가 0인 case
				f *= (-1);
				fn = i;
				break;
			}
			else {
				if (!(str[i - 1] >= '0' && str[i - 1] <= '9')) {
					f *= (-1);
					fn = i;
					break;
				}
				else
					break;
			}
		}
		else 
			break;
	}
	if (c == '+')
		sum = s + f;
	else if (c == '*')
		sum = s * f;
	else
		sum = f - s;
	front = str.substr(0, fn); // 연산에 사용되지 않은 앞부분 string
	back = str.substr(sn + 1, str.size() - 1); // 연산에 사용된 뒷부분 string 
	return str = front + std::to_string(sum) + back; // 다시 string 형태로 반환
}

long long max(long a, long b) {
	return a > b ? a : b;
}

long long solution(string expression) {
	long long answer = 0;
	string arr[6] = { "+*-","+-*","-+*","-*+","*+-","*-+" }; //연산의 순서에 따라 배열로 정의
	for (int i = 0; i < 6; i++) 
	{
		string str = expression;
		for (int n = 0; n < 3; n++) 
		{
			for (int j = 1; j < str.size(); j++) 
			{
				if (str[j] == arr[i][n] && (str[j-1] >= '0' && str[j-1] <= '9'))  //해당 연산자 체크 / find함수 사용 가능
				{
					str = cal(str, j, arr[i][n]);
				}
			}
		}
		answer = max(answer, abs(stoi(str)));
	}

	return answer;
}

int main(void) {
	string s = "100-200*300-500+20"; //60420   //1번 예제
	s = "50*6-3*2"; //300		2번예제
	cout << solution(s);
}
//https://tech.kakao.com/2020/07/01/2020-internship-test/
//0503 cal함수에서 숫자 추출하는 부분을 좀 더 고민해봐야겠음...
//0504 cal함수에서 숫자 추출하고 연산하는 부분까지 했음 앞뒤로 남은 문자열과 함께 다시 합치는 부분  
//0505 cal함수에서 나머지 부분의 문자열을 추출하는 부분에서 substr을 사용, 연산의 결과가 -일때 연산부호와 숫자부호를 구별하는 flag //프로그래머스 제출 
