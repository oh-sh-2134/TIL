#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int student[30];

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	for (auto iter : lost)
		student[iter]--;
	for (auto iter : reserve)
		student[iter]++;
	for (int i = 1; i <= n; i++) {
		if (student[i] == -1) {
			if (student[i - 1] == 1)
				student[i - 1] = student[i] = 0;
			else if (student[i + 1] == 1)
				student[i + 1] = student[i] = 0;
		}
		if (student[i] >= 0)answer++;
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/42862