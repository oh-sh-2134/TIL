#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
	int answer = 0;
	vector<bool> wall(n + 1, true);
	for (auto iter : section)
		wall[iter] = false;

	for (int i = 1; i <= n; i++) {
		if (wall[i]) continue;
		answer++;
		for (int j = 1; j < m; j++) {
			if (i > n) break;
			wall[i++] = true;
		}

	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/161989