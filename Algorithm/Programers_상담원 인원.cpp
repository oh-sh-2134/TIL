#include <string>
#include <vector>
#include <queue>
#define MAX 987654321
using namespace std;

vector<vector<int>>combinations;

int min(int a, int b) {
	return a > b ? b : a;
}

void getCombination(int n, int idx, vector<int> combination) {

	if (n == 0) {
		combinations.push_back(combination);
		return;
	}

	for (int i = idx; i < combination.size(); i++) {
		combination[i]++;
		getCombination(n - 1, idx, combination);
		combination[i]--;
	}
	return;
}

int calculation(vector<vector<int>> &reqs, vector<int> combination) {
	int waitingTime = 0;
	priority_queue<int, vector<int>, greater<int>> pq[combination.size()];

	for (int i = 1; i < combination.size(); i++) {
		for (int j = 0; j < combination[i]; j++) {
			pq[i].push(0);
		}
	}
	for (vector<int> req : reqs) {
		int start = req[0];
		int duration = req[1];
		int type = req[2];
		int end = pq[type].top();
		pq[type].pop();

		if (end > start) {
			waitingTime += end - start;
			pq[type].push(end + duration);
		}
		else {
			pq[type].push(start + duration);
		}
	}
	return waitingTime;
}

int solution(int k, int n, vector<vector<int>> reqs) {

	vector<int> combination(k + 1, 1);
	getCombination(n - k, 1, combination);
	int answer = MAX;
	for (vector<int> combination : combinations) {
		answer = min(answer, calculation(reqs, combination));
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/214288