#include<iostream>
#include <queue>
#include<stack>
#include<cstring>
using namespace std;

int arr[101][101];
int state[101][101];
bool visited[101][101];
int N, L, R;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void Input() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}

bool stateCheck() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (state[i][j]) return false;
		}
	}
	return true;
}
bool bfs() {
	stack<pair<int, int>> stk;
	queue <pair<int, int>> graph;
	graph.push({ 0, 0 });

	while (!graph.empty()) {
		int y = graph.front().first;
		int x = graph.front().second;
		graph.pop();
		if (visited[y][x]) continue;
		visited[y][x] = true;
		

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
			if (abs(arr[y][x] - arr[ny][nx]) >= L && abs(arr[y][x] - arr[ny][nx]) <= R) {
				state[y][x] = 1;
				state[ny][nx] = 1;
			}
			if(!visited[ny][nx])
				graph.push({ ny,nx });
		}
	}

	if(stateCheck()) return false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (state[i][j]) {
				int cnt = 0;
				int total = 0;
				int result = 0;
				graph.push({ i,j });
				while (!graph.empty()) {
					int y = graph.front().first;
					int x = graph.front().second;
					graph.pop();

					if (!state[y][x]) continue;
					state[y][x] = 0;
					cnt++;
					total += arr[y][x];
					stk.push({ y,x });
					for (int i = 0; i < 4; i++) {
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
						if(state[ny][nx])
							graph.push({ ny,nx });
					}
				}
				result = total / cnt;

				while (!stk.empty()) {
					int y = stk.top().first;
					int x = stk.top().second;
					stk.pop();
					arr[y][x] = result;
				}
			}
		}
	}
	return true;


}

int solution() {
	int cnt = 0;
	while (bfs()) {
		memset(state, 0, sizeof(state));
		memset(visited, false, sizeof(visited));
		cnt++;
	}
	return cnt;
}

int main(void) {
	
	Input();
	int sol = solution();
	cout << sol;
}

//https://www.acmicpc.net/problem/16234
//4퍼에서 입구컷 ㄷㄷ;