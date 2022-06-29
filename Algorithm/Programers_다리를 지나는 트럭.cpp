#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int sec = 1;
	queue<int> t;
	for (auto iter : truck_weights)
		t.push(iter);
	queue<pair<int, int>>q;
	q.push({ t.front(),bridge_length });
	weight -= t.front();
	t.pop();

	while (!q.empty()) {
		sec++;
		int size = q.size();
		//트럭들이 한칸씩 앞으로 이동
		for (int i = 0; i < size; i++) {
			int currentWeight = q.front().first;
			int currentLength = q.front().second - 1;
			q.pop();
			if (currentLength == 0) {
				weight += currentWeight;
				continue;
			}
			q.push({ currentWeight, currentLength });
		}
		//새로운 트럭이 들어 올 수 없다면 패스
		if (t.empty()) continue;
		if (weight - t.front() < 0)
			continue;
		weight -= t.front();
		q.push({ t.front(),bridge_length });
		t.pop();
	}
	int answer = sec;
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42583
