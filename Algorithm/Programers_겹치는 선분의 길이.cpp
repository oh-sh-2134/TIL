#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
	int answer = 0;
	vector<int> fields(200);
	for (auto line : lines) {
		fields[line[0] + 100]++;
		fields[line[1] + 100]--;
	}
	if (fields[0] > 1) answer++;
	for (int i = 0; i < 200; i++) {
		fields[i + 1] += fields[i];
		if (fields[i + 1] > 1) answer++;
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/120876