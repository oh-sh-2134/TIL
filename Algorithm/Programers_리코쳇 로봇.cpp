#include <string>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

class Point {
public:
	Point(int _y, int _x) {
		y = _y;
		x = _x;
	}
	void move(int _y, int _x) {
		y += _y;
		x += _x;
		cnt++;
	}
	void addCnt() {
		cnt++;
	}
	int getY() {
		return y;
	}
	int getX() {
		return x;
	}
	int getCnt() {
		return cnt;
	}
private:
	int y = 0;
	int x = 0;
	int cnt = 0;

};

int solution(vector<string> board) {
	int answer = -1;
	queue<Point> q;
	vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(), false));
	for (int i = 0; i < board.size(); i++) {
		if (q.size() > 0) break;
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] != 'R') continue;
			q.push(Point(i, j));
			visited[i][j] = true;
			break;
		}
	}
	while (!q.empty()) {
		Point cur = q.front();
		q.pop();
		if (board[cur.getY()][cur.getX()] == 'G') {
			answer = cur.getCnt();
			break;
		}
		for (int i = 0; i < 4; i++) {
			bool flag = true;
			Point nxt = Point(cur);
			int my = 0, mx = 0;
			while (true) {
				my += dy[i];
				mx += dx[i];
				if (nxt.getY() + my < board.size() &&
					nxt.getY() + my >= 0 &&
					nxt.getX() + mx < board[0].size() &&
					nxt.getX() + mx >= 0 &&
					board[nxt.getY() + my][nxt.getX() + mx] != 'D')
					continue;
				my -= dy[i];
				mx -= dx[i];
				break;
			}
			nxt.move(my, mx);
			if (visited[nxt.getY()][nxt.getX()]) continue;
			visited[nxt.getY()][nxt.getX()] = true;
			q.push(nxt);
		}
	}
	return answer;
}
int main(void) {
	vector<string> v = { "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." };
	solution(v);
}
//https://school.programmers.co.kr/learn/courses/30/lessons/169199