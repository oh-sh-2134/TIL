#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std; 
string Add(string &s1, string &s2) { 
	string result(max(s1.size(), s2.size()), '0'); // 가장 큰 수만큼 크기 배정
	bool carry = false; 
	for (int i = 0; i < result.size(); i++) 
	{ 
		int temp = carry;  // 이전 연산에서 올림수 발생시 추가 해줘야 함
		carry = false; 
		if (i < s1.size()) 
			temp += s1[s1.size() - i - 1] - '0'; //string을 int로 바꾸려면 '0'을 빼줘야 함

		if (i < s2.size()) 
			temp += s2[s2.size() - i - 1] - '0';

		if (temp >= 10) {  // 더해서 올림수가 발생하는지 체크
			carry = true; 
			temp -= 10; 
		} 
		result[result.size() - i - 1] = temp + '0'; //기존에 있던 자릿수일 경우 result에 추가
	} 
	if (carry) // 올림수가 발생해서 새로운 자릿수가 발생했을때만 추가
		result.insert(result.begin(), '1'); 

	return result; 
} 

int main(void) { 
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int N; cin >> N; 
	string a = "0", b = "1"; 
	if (N == 0) cout << a << "\n"; 
	else if (N == 1) cout << b << "\n"; 
	else { 
		string result; 
		for (int i = 0; i <= N - 2; i++) { 
			result = Add(a, b); 
			a = b; 
			b = result; 
		} 
		cout << result << "\n"; 
	} 
	return 0; 
}
//https://www.acmicpc.net/problem/10826
//쉬고 싶은 날이라 쉬운문제를 골랐는데 알고 보니 long long으로도 받아도 10000번째 배열은 범위를 벗어 남
//string으로 구현했음 올림수 발생할때를 체크해서 담았음