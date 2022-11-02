#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = n;
	for (int i = 1; i <= n / 2; i++) {
		if (n%i == 0)
			answer += i;
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12928