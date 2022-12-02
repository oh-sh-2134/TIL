#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	priority_queue<int> pq(works.begin(), works.end());
	while (pq.top()*n) {
		int i = pq.top() - 1;
		pq.pop();
		pq.push(i);
		n--;
	}
	while (!pq.empty()) {
		answer += pq.top()*pq.top();
		pq.pop();
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12927