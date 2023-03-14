#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> solution(int k, vector<int> score) {
	vector<int> answer;
	priority_queue<int,vector<int>,greater<int>> pq;
	for (auto iter : score) {
		pq.push(iter);
		while (pq.size() > k) {
			pq.pop();
		}
		answer.push_back(pq.top());
	}
	return answer;
}

int main(void) {
	vector<int> v = { 10, 100, 20, 150, 1, 100, 200 };
	solution(4,v);
}