#include <iostream>
#include <string>
#include <vector>
using namespace std;

int r, c;
int cnt;
// y의 대각선 축으로 먼저 탐색하게 하는게 포인트
//위를 먼저 방문할 경우에 아래를 먼저 방문할때 더 큰 파이프라인 갯수가 나올경우를 빠뜨림
int my[3] = { -1,0,1 };
int mx[3] = { 1,1,1 };
vector<vector<char>> graph;

void input() {
	cin >> r >> c;
	graph.resize(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> graph[i][j];
		}
	}
}

bool dfs(int y, int x) {
	if (x == c - 1) {
		cnt++;
		return true;
	}

	graph[y][x] = 'x';
	for (int i = 0; i < 3; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (ny >= r || ny<0 || nx>=c || nx < 0 ) continue;
		if (graph[ny][nx] == 'x') continue;
		//탐색을 더 이어갈지 체크
		if (dfs(ny,nx))
			return true;
	}
	return false;

}
void solution() {
	for (int i = 0; i < r; i++) {
		dfs(i, 0);
	}
	cout << cnt;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/3109