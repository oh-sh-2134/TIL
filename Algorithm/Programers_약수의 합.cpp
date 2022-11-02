#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = n;
	//n의 약수는 n을 제외하고 n/2를 넘지않음
	for (int i = 1; i <= n / 2; i++) {
		if (n%i == 0)
			answer += i;
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12928
