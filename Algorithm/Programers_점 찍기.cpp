#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(int k, int d) {
	long long answer = 0;
	long long length = d;
	long long limit = length * length;

	for (long long i = 0; i <= d; i += k) {
		long long x = i * i;
		long long maxY = (long long)pow(limit - x, 0.5);
		answer += (maxY / k) + 1;
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/140107