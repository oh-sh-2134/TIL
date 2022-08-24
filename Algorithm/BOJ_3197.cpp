#include <iostream>
#include <queue>
using namespace std;



int R, S;
int days = 0;
vector<vector<char>> field;
vector<vector<bool>> visited;
queue<Point> mealtField;
Point becjo;

int mx[4] = { 0,0,1,-1 };
int my[4] = { 1,-1,0,0 };


class Point {
public:
	int y, x;
	Point(int a, int b) {
		y = a;
		x = b;
	}
};



void input() {
	cin >> R >> S;
	field = vector<vector<char>>(R, vector<char>(S, ' '));
	visited = vector<vector<bool>>(R, vector<bool>(S, false));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			cin >> field[i][j];
			if (field[i][j] == 'L') {
				becjo = Point(i, j);
			}
		}
	}
}

void meltIce() {
	while (!mealtField.empty()){
		field[mealtField.front().y][mealtField.front().x] = '.';
	}
}

bool findBecjo(Point p) {
	queue<Point> q;
	q.push(p);
	visited[p.y][p.x] = true;
	while (!q.empty()) {
		Point cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int y = my[i] + cur.y;
			int x = mx[i] + cur.x;
			if (y >= R || y < 0 || x >= S || x < 0) continue;
			if (visited[y][x]) continue;
			if (field[y][x] == 'X') continue;
			if (field[y][x] == 'L') return true;
			visited[y][x] = true;
			q.push(Point(y, x));
		}


	}
	return false;
}

void BFS(int cy, int cx) {
	queue<Point> q;
	q.push(Point(cy,cx));
	visited[cy][cx] = true;
	while (!q.empty()) {
		Point cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int y = my[i] + cur.y;
			int x = mx[i] + cur.x;
			if (y >= R || y < 0 || x >= S || x < 0) continue;
			if (visited[y][x]) continue;
			if (field[y][x] == '.') {
				if (mealtField.back().y == cur.y && mealtField.back().x == cur.x) continue;
				mealtField.push(cur);
			}
			if (field[y][x] == 'L') continue;
			visited[y][x] = true;
			q.push(Point(y, x));
		}		
	}
}

void solution() {
	while (true) {
		fill(visited.begin(), visited.end(), false);
		if (findBecjo(becjo)) break;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < S; j++) {
				if (visited[i][j]) continue;
				BFS(i,j);
			}
		}
		meltIce();
		days++;
	}
	cout << days;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/3197