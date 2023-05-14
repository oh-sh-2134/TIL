#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
	vector<int> answer;
	int n = ((total * 2) / num + 1 - num) / 2;
	for (int i = 0; i < num; i++)
		answer.push_back(n + i);
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/120923