#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
	long long answer = 0;
	auto max = [](long long a, long long b) -> long long {return a > b ? a : b; };
	if (b != max(a, b)) {
		long long temp = b;
		b = a;
		a = temp;
	}
	for (long long i = a; i <= b; i++)
		answer += i;
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12912