#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<cstring>
#define MAX 20001
using namespace std;

vector<int> v[MAX];
int check[MAX];
bool visited[MAX];
int t, n, c, a, b;

void makeTree(int a, int b) {
	v[a].push_back(b);
	v[b].push_back(a);
}
bool dfs(int a) {
	stack<int> s;
	s.push(a);
	while (!s.empty()) {
		int scnt = s.size();
		for (int i = 0; i < scnt; i++) {
			int x = s.top();
			s.pop();
			if (visited[x]) continue;
			visited[x] = true;
			for (int j = 0; j < v[x].size(); j++) {
				int y = v[x][j];
				if (y > n) continue;;
				if (check[x] == check[y]) {
					return false; // 이분 그래프가 아니라면 더 이상 탐색할 필요 없음
				}
				s.push(y);
			}
		}
	}
	return true;
}
void bfs(int a) {
	int rvs = 1;
	queue<int>q;
	q.push(a);
	while (!q.empty()) {
		int cnt = q.size();
		for (int i = 0; i < cnt; i++) { // 다음 정점만 방문할 수 있도록
			int x = q.front();
			q.pop();
			if (check[x] != 0) continue;
			check[x] = rvs;
			for (int j = 0; j < v[x].size(); j++) {
				int y = v[x][j];
				if (y > n) continue;
				q.push(v[x][j]);
			}
		}
		rvs *= -1; // 색을 뒤집어 줘야함
	}
}



int main(void) {
	cin >> t;
	int sol[5] = { 1, 1,1,1,1 };
	for (int i = 0; i < t; i++) {
		cin >> n >> c;
		for (int j = 0; j < c; j++) {
			cin >> a >> b;
			makeTree(a, b);
		}
		if (n == 1) {
			sol[i] = true;
			continue;
		}
		for (int j = 1; j <= n; j++) {
			bfs(j);
		}
		for (int j = 1; j <= n; j++) {
			if (!dfs(j)) {
				sol[i] = 0;
				break; // 이분그래프가 아니라면 더 이상 탐색할 필요가 없음
			}
		}
		for (int j = 1; j <= n; j++) {
			v[j].clear();
		}
		memset(visited, false, sizeof(visited));
		memset(check, 0, sizeof(check));
	}
	for (int i = 0; i < t; i++) {
		if (sol[i]) cout << "YES\n";
		else cout << "NO\n";
	}
}
/*2
3 3
1 2
2 3
3 1
2 1
1 2
NO
YES*/
//https://www.acmicpc.net/problem/1707
//bfs로 색칠 후 bfs로 체크 했음 
//코드가 너무 지저분 해졌지만 다음에 파이썬으로 다시푸는 걸로...
