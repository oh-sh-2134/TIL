#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	vector<vector<pair<int, int>>> adj(N + 1);
	vector<int> dist(N + 1, 987654321);
	priority_queue<pair<int, int> > q;
	for (auto iter : road) {
		adj[iter[0]].push_back({ iter[1],iter[2] });
		adj[iter[1]].push_back({ iter[0],iter[2] });
	}
	q.push({ 0,1 });
	dist[1] = 0;

	//우선큐를 이용한 다익스트라로 간선 정리
	while (!q.empty()) {
		int current_dist = -q.top().first;
		int current = q.top().second;
		q.pop();
		if (current_dist > dist[current]) continue;

		for (int i = 0; i < adj[current].size(); i++) {
			int next = adj[current][i].first;
			int next_dist = adj[current][i].second;

			if (dist[next] > next_dist + current_dist) {
				dist[next] = next_dist + current_dist;
				q.push({ -dist[next],next });
			}

		}
	}

	for (auto iter : dist)
		if (iter <= K) answer++;



	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12978