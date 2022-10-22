#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 1;
	for (int i = 1; i < n; i++) {
		int sum = i, cur = i;
		while (sum < n) {
			sum += ++cur;
			if (sum == n) {
				answer++;
				break;
			}
		}
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12924