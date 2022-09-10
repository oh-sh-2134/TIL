#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, P, K, maxCost, sol;
vector<vector<pair<int,int>>> node;
void input() {
	cin >> N >> P >> K;
	node.resize(N + 1);
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
		maxCost = max(maxCost, c);
	}
}

bool dijkstra(int target) {
	vector<int> cost(N + 1, N);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int currentNode = pq.top().second;
		int currentCost = pq.top().first;
		pq.pop();
		if (cost[currentNode] <= currentCost)  continue;
		cost[currentNode] = currentCost;

		for (int i = 0; i < node[currentNode].size(); i++) {
			int nextNode = node[currentNode][i].first;
			int nextCost = currentCost + (node[currentNode][i].second > target);
			if (nextCost < cost[currentNode]) {
				cost[currentNode] = nextCost;
				pq.push({ nextNode ,nextCost });
			}
		}
	}
	return (cost[N] <= K);
}

void binarySearch() {
	int l, r, mid;
	l = 0;
	r = maxCost;
	sol = -1;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (dijkstra(mid)) {
			r = mid - 1;
			sol = mid;
		}
		else
			l = mid + 1;
	}
}

void solution() {
	binarySearch();
	cout << sol;
}
int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/1800