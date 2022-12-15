#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int min(int a, int b) {
	return a > b ? b : a;
}
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
	vector<int> answer;
	vector<int> dist(n + 1, INF);
	vector<vector<pair<int, int>>> adj(n + 1);

	for (auto & iter : roads) {
		adj[iter[0]].push_back({ iter[1],1 });
		adj[iter[1]].push_back({ iter[0],1 });
	}
	priority_queue<pair<int, int>> q;
	q.push({ destination, 0 });
	dist[destination] = 0;
	while (!q.empty()) {
		int cur = q.top().first;
		int curCost = -q.top().second;
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i].first;
			int nxtCost = adj[cur][i].second + curCost;
			if (nxtCost < dist[nxt]) {
				dist[nxt] = nxtCost;
				q.push({ nxt,-nxtCost });
			}
		}
	}
	for (auto iter : sources) {
		if (dist[iter] == INF) answer.push_back(-1);
		else answer.push_back(dist[iter]);
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/132266