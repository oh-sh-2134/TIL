#include<iostream>
#include<cstring>
using namespace std;


int N;
char map[101][101];
bool visited[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx>=N || ny<0 || ny>=N) continue;
		if (visited[ny][nx] || map[y][x] != map[ny][nx]) continue;

		visited[ny][nx] = true;
		dfs(ny,nx);
	}
}

int solve() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				dfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}


int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin>>map[i][j];
		}
	}
	int sol1 = solve();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
			//visited[i][j] = false;
		}
	}
	memset(visited, false, sizeof(visited));
	int sol2 = solve();

	cout << sol1 << " " << sol2;
}

//https://www.acmicpc.net/problem/10026
//그래프를 이용한 dfs를 처음푸는데 감이 안잡혀서 참조를 많이했다
//이 느낌으로 dfs bfs문제를 집중적으로 풀어야겠다.