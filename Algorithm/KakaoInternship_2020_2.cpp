#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
vector<char> ex;
vector<long long> nums;
pair<string, bool> oper[3] = { {"+",false}, {"-",false}, {"*",false} };
long long maxIdx;

long long max(long long  a, long long b) { return a > b ? a : b; }

//연산자랑 숫자주면 계산해주는 함수
long long getResult(char ex, long long a, long long b) {
	switch (ex)
	{
	case '*':
		return a * b;

	case '+':
		return a + b;

	case '-':
		return a - b;
	}
}

//연산의 순서가 정해지면 계산시작
long long cal(string exp) {
	vector<char> tempEx = ex;
	vector<long long> tempNums = nums;
	for (int i = 0; i < 3; i++) {
		for (int e = 0; e < tempEx.size(); e++) {
			//연산 순서에 맞는 연산이 나올때
			if (exp[i] == tempEx[e]) {
				//숫자2개 연산자 하나로 계산하기 때문에 계산 결과를 첫번째 숫자 vector에 넣고 숫자와 연산자 하나씩 삭제
				tempNums[e] = getResult(tempEx[e], tempNums[e], tempNums[e + 1]);
				tempNums.erase(tempNums.begin() + e + 1);
				tempEx.erase(tempEx.begin() + e);
				e--;
			}
		}
	}
	return abs(tempNums[0]);
}

void dfs(string exp) {
	//연산의 순서가 정해지면
	if (exp.size() == 3) {
		maxIdx = max(maxIdx, cal(exp));
	}

	for (int i = 0; i < 3; i++) {
		if (oper[i].second) continue;
		oper[i].second = true;
		dfs(exp + oper[i].first);
		oper[i].second = false;
	}

}

// 파싱함수
void convert(string s) {
	int i = 0;
	string num = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*' || s[i] == '+' || s[i] == '-') {
			ex.push_back(s[i]);
			nums.push_back(stoi(num));
			num.clear();
			num.resize(0);
			continue;
		}
		num.push_back(s[i]);
	}
	nums.push_back(stoi(num));
}

long long solution(string expression) {
	convert(expression);
	for (int i = 0; i < 3; i++) {
		oper[i].second = true;
		dfs(oper[i].first);
		oper[i].second = false;
	}
	long long answer = maxIdx;
	return answer;
}

int main(void) {
	string s = "100-200*300-500+20"; //60420   //1번 예제
	//s = "50*6-3*2"; //300		2번예제
	cout << solution(s);
}
//https://tech.kakao.com/2020/07/01/2020-internship-test/
//0503 cal함수에서 숫자 추출하는 부분을 좀 더 고민해봐야겠음...
//0504 cal함수에서 숫자 추출하고 연산하는 부분까지 했음 앞뒤로 남은 문자열과 함께 다시 합치는 부분  
//0505 cal함수에서 나머지 부분의 문자열을 추출하는 부분에서 substr을 사용, 연산의 결과가 -일때 연산부호와 숫자부호를 구별하는 flag //프로그래머스 제출 
//0503 1년만에 다시 돌아왔는데 맞은줄 알고 있었음 완전탐색으로 풀이함 실력이 늘어가는게 느껴짐 뿌듯 >_<
