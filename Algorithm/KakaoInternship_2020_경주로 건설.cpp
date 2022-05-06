#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int load[4][25][25];


int min(int a, int b) { return a > b ? b : a; }

int solution(vector<vector<int>> board) {

	N = board.size();
	for (int c = 0; c < 4; c++) 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				load[c][i][j] = INF;

	int answer = INF;
	queue<pair<pair<int, int>, pair<int, int>>>q;
	q.push({ {0,0},{0,-1 } });
	for (int i = 0; i < 4; i++) {
		load[i][0][0] = 0;
	}
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cost = q.front().second.first;
		int dir = q.front().second.second;
		q.pop();
		if (y == N - 1 && x == N - 1)
			//시작점에서 500으로 시작됨
			answer = min(answer, load[dir][y][x]-500);
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
			if (board[ny][nx] == 1) continue;
			int newCost = cost + 100;
			if (dir != i) newCost += 500;

			if (newCost <= load[i][ny][nx]) {
				load[i][ny][nx] = newCost;
				q.push({ {ny,nx},{newCost,i} });
			}

		}
	}
	return answer;
}

int main(void) {
	vector<vector<int>> v = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	vector<vector<int>> v2 = {{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}};
	solution(v2);
}