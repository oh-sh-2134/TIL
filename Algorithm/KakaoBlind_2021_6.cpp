#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;


vector<vector<int>>Board;

int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

struct Point
{
	int row;
	int col;
	int cnt;
};

int min(int a, int b) { return a > b ? b : a; }

int bfs(Point src, Point dist) {
	bool visited[4][4] = { false };
	queue<Point>q;
	q.push(src);
	while (!q.empty()) {
		Point curr = q.front();
		q.pop();
		if (curr.row == dist.row && curr.col == dist.col) return curr.cnt;


		for (int i = 0; i < 4; i++) {
			int nr = curr.row + d[i][0], nc = curr.col + d[i][1];
			if (nr < 0 || nr>3 || nc < 0 || nc>3) continue;

			if (!visited[nr][nc]) {
				visited[nr][nc] = true;
				Point p;
				p.row = nr;
				p.col = nc;
				p.cnt = curr.cnt + 1;
				q.push(p);
			}

			for (int j=0; j < 2; j++) {
				if (Board[nr][nc] != 0) break;
				if (nr + d[i][0] < 0 || nr + d[i][0]>3 || nc + d[i][1] < 0 || nc + d[i][1] >3) break;

				nr += d[i][0];
				nc += d[i][1];
			}

			if (!visited[nr][nc]) {
				visited[nr][nc] = true;
				Point p;
				p.row = nr;
				p.col = nc;
				p.cnt = curr.cnt +1;
				q.push(p);
			}
		}
	}
	return INF;
}

int permutate(Point src) {
	int ret = INF;
	
	for (int n = 1; n < 7; n++) {
		vector<Point> card;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (Board[i][j] == n) {
					Point p;
					p.row = i;
					p.col = j;
					p.cnt = 0;
					card.push_back(p);
				}
			}
		}

		if (card.size() == 0) continue;

		int first = bfs(src, card[0]) + bfs(card[0], card[1]) + 2;
		int second = bfs(src, card[1]) + bfs(card[1], card[0]) + 2;

		for (int i = 0; i < 2; i++) {
			Board[card[i].row][card[i].col] = 0;
		}
		ret = min(ret,first + permutate(card[1]));
		ret = min(ret, second + permutate(card[0]));

		for (int i = 0; i < 2; i++) {
			Board[card[i].row][card[i].col] = n;
		}
	}
	if (ret == INF) return 0;

	return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
	int answer = 0;
	Board = board;
	Point p;
	p.row = r;
	p.col = c;
	p.cnt = 0;
	return permutate(p);
}

