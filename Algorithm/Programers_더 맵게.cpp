#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	priority_queue<int, vector<int>, greater<int>> q;
	int answer = 0;
	for (auto iter : scoville)
		q.push(iter);
	while (q.top() <= K) {
		if (q.size() == 1) {
			answer = -1;
			break;
		}
		int first = q.top();
		q.pop();
		int second = q.top();
		q.pop();
		int result = first + second * 2;
		q.push(result);
		answer++;
	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42626