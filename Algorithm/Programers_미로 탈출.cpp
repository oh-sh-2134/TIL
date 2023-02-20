#include <string>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

class Point {
public:
	Point() {}
	Point(int _y, int _x) {
		y = _y;
		x = _x;
		lever = false;
	}
	Point(int _y, int _x, bool _lever) {
		y = _y;
		x = _x;
		lever = _lever;
	}

	int getY() {
		return y;
	}
	int getX() {
		return x;
	}
	void setArriveLiver() {
		lever = true;
	}

	bool isLever() {
		return lever;
	}

private:
	int y;
	int x;
	bool lever;
};

int solution(vector<string> maps) {
	int answer = 0;
	int n = maps.size(), m = maps[0].size();
	Point start, end, lever;
	vector<vector<vector<int>>> arr = vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(m, -1)));
	vector<vector<vector<bool>>> visited = vector<vector<vector<bool>>>(2, vector<vector<bool>>(n, vector<bool>(m, false)));
	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < maps[i].size(); j++) {
			if (maps[i].at(j) == 'S') {
				start = Point(i, j);
			}
			else if (maps[i].at(j) == 'L') {
				lever = Point(i, j);
			}
			else if (maps[i].at(j) == 'E') {
				end = Point(i, j);
			}
		}
	}
	queue<Point> q;
	q.push(start);
	visited[0][start.getY()][start.getX()] = true;
	arr[0][start.getY()][start.getX()] = 0;
	while (!q.empty()) {
		int y = q.front().getY();
		int x = q.front().getX();
		bool lever = q.front().isLever();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			bool nlever = lever;
			if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
			if (maps[ny][nx] == 'X') continue;
			if (visited[nlever][ny][nx]) continue;
			visited[nlever][ny][nx] = true;
			if (maps[ny][nx] == 'L')
				nlever = true;
			arr[nlever][ny][nx] = arr[lever][y][x] + 1;
			q.push(Point(ny, nx, nlever));
		}
	}
	answer = arr[1][end.getY()][end.getX()];
	return answer;
}


int main(void) {
	vector<string> v = { "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" };
	solution(v);
}
//https://school.programmers.co.kr/learn/courses/30/lessons/159993