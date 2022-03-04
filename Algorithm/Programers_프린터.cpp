#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	priority_queue<int> pq;
	queue<pair<int, int>> q;
	int pos = 0;
	for (auto iter : priorities) {
		pq.push(iter);
		q.push({ iter,pos++ });
	}

	while (!q.empty()) {
		int priority = q.front().first;
		int pos = q.front().second;
		q.pop();
		if (pq.top() != priority) {
			q.push({ priority,pos });
			continue;
		}
		pq.pop();
		answer++;
		if (location == pos)
			break;
	}

	return answer;
}