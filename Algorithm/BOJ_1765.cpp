#include<iostream>
#include<vector>


using namespace std;

vector<vector<int>> team;
vector<vector<int>> enemy;
vector<bool> visited;
int s, t;
void input() {
	cin >> s;
	team = vector<vector<int>>(s + 1);
	enemy= vector<vector<int>>(s + 1);
	visited = vector<bool>(s + 1, false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		if (c == 'E') {
			enemy[a].push_back(b);
			enemy[b].push_back(a);
		}
		else {
			team[a].push_back(b);
			team[b].push_back(a);
		}
	}
}

void dfs(int cur) {
	visited[cur] = true;
	for (int i = 0; i < team[cur].size(); i++) {
		int next = team[cur][i];
		if (visited[next]) continue;
		dfs(next);
	}

	for (int i = 0; i < enemy[cur].size();i++) {
		int next = enemy[cur][i];
		for (int j = 0; j < enemy[next].size(); j++) {
			int next2 = enemy[next][j];
			if (visited[next2]) continue;
			dfs(next2);
		}
	}
}

void solution() {
	int answer = 0;
	for (int i = 1; i <= s; i++) {
		if (visited[i]) continue;
		dfs(i);
		answer++;
	}
	cout << answer;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/1765