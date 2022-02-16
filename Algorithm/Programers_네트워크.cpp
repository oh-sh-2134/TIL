#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[201];
bool visited[2001];
int sol;

void bfs(int cur) {
	if (visited[cur]) return;
	visited[cur] = true;

	queue<int> q;
	q.push(cur);

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < adj[current].size(); i++) {
			int next = adj[current][i];
			if (visited[next]) continue;
			q.push(next);
			visited[next] = true;
		}
		if (q.size() == 0) sol++;
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	fill(visited, visited + n, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (computers[i][j])
				adj[i].push_back(j);
		}
	}
	for (int i = 0; i < n; i++)
		bfs(i);
	answer = sol;
	return answer;
}