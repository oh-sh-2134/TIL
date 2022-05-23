#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int>> adj[5001];
bool visited[5001];
int n, q;

void input() {
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		//네트워크 간선 생성
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
}

void bfs(int USADO, int start) {
	int cnt = 0;
	queue<int> q;
	q.push(start);
	vector<bool> visited(n + 1, false);
	visited[start] = true;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < adj[current].size(); i++) {
			//방문 여부 체크
			if (visited[adj[current][i].first]) continue;
			//해당 노선의 USADO 확인
			if (adj[current][i].second < USADO) continue;
			visited[adj[current][i].first] = true;
			q.push(adj[current][i].first);
			cnt++;
		}
	}
	cout << cnt << "\n";
}

void solution() {
	int v, k;
	cin >> v >> k;
	
	bfs(v, k);
}
int main(void) {
	input();
	for (int i = 0; i < q; i++) {
		solution();
	}
}
//https://www.acmicpc.net/problem/15591