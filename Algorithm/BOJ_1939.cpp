#include <iostream>
#include <vector>
using namespace std;

int S, E;
int N, M;
int maxW;
vector<vector<pair<int, int>>> land;
vector<bool> visited;

void input() {
	cin >> N >> M;
	land.resize(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < M; i++) {
		int s, e, r;
		cin >> s >> e >> r;
		land[s].push_back({ e,r });
		land[e].push_back({ s,r });
		if (r > maxW) maxW = r;
	}
	cin >> S >> E;
}

/*dfs 활용*/
void findMax(int cur, int target) {
	for (int i = 0; i < land[cur].size(); i++) {
		int next = land[cur][i].first;
		int weight = land[cur][i].second;
		if (weight < target) continue;
		if (visited[next]) continue;
		visited[next] = true;
		findMax(next, target);
	}
}

int BinarySearch(int l, int r) {
	while (l <= r) {
		int mid = (r + l) >> 1;
		visited.clear();
		visited.resize(N + 1, false);
		visited[S] = true;
		findMax(S, mid);
		if (visited[E]) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return r;
}


void solution() {
	int res = BinarySearch(0, maxW);
	cout << res;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/1939