#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int one[5] = { 1, 2, 3, 4, 5 };
	int two[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int thr[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	int oneCnt = 0;
	int twoCnt = 0;
	int thrCnt = 0;

	for (int i = 0; i < answers.size(); i++) {
		if (one[i % 5] == answers[i]) oneCnt++;
		if (two[i % 8] == answers[i]) twoCnt++;
		if (thr[i % 10] == answers[i]) thrCnt++;
	}

	int maxCnt = max(oneCnt, twoCnt);
	maxCnt = max(maxCnt, thrCnt);

	if (maxCnt == oneCnt) answer.push_back(1);
	if (maxCnt == twoCnt) answer.push_back(2);
	if (maxCnt == thrCnt) answer.push_back(3);

	return answer;
}