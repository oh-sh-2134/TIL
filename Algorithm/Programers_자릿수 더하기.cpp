#include <iostream>

using namespace std;
int solution(int n)
{
	int answer = 0;
	for (; n > 0; n /= 10)
		answer += n % 10;
	return answer;
}//https://school.programmers.co.kr/learn/courses/30/lessons/12931