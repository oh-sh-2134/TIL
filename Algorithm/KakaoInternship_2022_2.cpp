#include <string>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
	int answer = -1;
	queue<int>q1;
	queue<int>q2;
	long long q1Sum = 0, q2Sum = 0;
	for (auto iter : queue1) {
		q1.push(iter);
		q1Sum += iter;
	}
	for (auto iter : queue2) {
		q2.push(iter);
		q2Sum += iter;
	}
	//둘의 합이 홀 수 일때
	if ((q1Sum + q2Sum) & 1) return answer;
	long long cnt = 0;
	while (q1Sum != q2Sum) {
		// q1과 q2를 모두 순회했을때
		if (cnt > (q1.size() + q2.size() + 2)) return answer;
		//q1의 합이 클때
		if (q1Sum > q2Sum) { 
			q1Sum -= q1.front();
			q2Sum += q1.front();
			q2.push(q1.front());
			q1.pop();
		}
		// q2의 합이 클때
		else {
			q2Sum -= q2.front();
			q1Sum += q2.front();
			q1.push(q2.front());
			q2.pop();
		}
		cnt++;
	}
	answer = cnt;
	return answer;
}