#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 987654321
using namespace std;

int N, P, K, maxCost;
vector<vector<pair<int,int>>> node;
void input() {
	cin >> N >> P >> K;
	node.resize(N + 1);
	for (int i = 0; i < P; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
		maxCost = max(maxCost, c);
	}
}

bool dijkstra(int target) {
	vector<int> cost(N + 1, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	cost[1] = 0;
	while (!pq.empty()) {
		int currentNode = pq.top().second;
		int currentCost = pq.top().first;
		pq.pop();
		if (cost[currentNode] < currentCost)  continue;

		for (int i = 0; i < node[currentNode].size(); i++) {
			int nextNode = node[currentNode][i].first;
			// 최소 가중치를 넘는 간선에는 1부여 아닐 경우 0으로 표시
			int nextCost = currentCost + (node[currentNode][i].second > target); 
			if (nextCost < cost[nextNode]) {
				cost[nextNode] = nextCost;
				pq.push({ nextCost ,nextNode });
			}
		}
	}
	return (cost[N] <= K); // 최소 가중치를 넘는 간선이 K개를 넘는지 확인
}
//매개변수 탐색 - 목표 최소 비용 결정
int binarySearch(int l, int r) {
	int mid;
	int sol = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (dijkstra(mid)) {
			r = mid - 1;
			sol = mid;
		}
		else
			l = mid + 1;
	}
	return sol;
}

//특정 가중치 이하의 간선으로만 경로를 구성할 수 있는지 판단해야 하는 문제
void solution() {
	cout << binarySearch(0, maxCost);
}
int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/1800
