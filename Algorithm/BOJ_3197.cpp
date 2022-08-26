#include <iostream>
#include <queue>
using namespace std;

class Point {
public:
	int y, x;
	Point(int a, int b) {
		y = a;
		x = b;
	}
	Point(){}
};

int R, S;
int days = 0;
vector<vector<char>> field;
vector<vector<bool>> visited;
queue<Point> mealtField;
Point becjo;

int mx[4] = { 0,0,1,-1 };
int my[4] = { 1,-1,0,0 };




void input() {
	cin >> R >> S;
	field = vector<vector<char>>(R, vector<char>(S, '.'));
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
			visited[y][x] = true;
			if ((field[cur.y][cur.x] == 'X' && field[y][x] == '.')|| (field[cur.y][cur.x] == '.' && field[y][x] == 'X')) {
				if (mealtField.empty()) {
					if (field[cur.y][cur.x] == 'X' && field[y][x] == '.') {
						mealtField.push(cur);
					}
					else {
						mealtField.push(Point(y, x));
					}
				}
				else if (mealtField.back().y != cur.y && mealtField.back().x != cur.x) {
					if (field[cur.y][cur.x] == 'X' && field[y][x] == '.') {
						mealtField.push(cur);
					}
					else {
						mealtField.push(Point(y, x));
					}
				}
			}
			if (field[y][x] == 'L') continue;
			
			q.push(Point(y, x));
		}		
	}
}

void solution() {
	while (true) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < S; j++) {
				visited[i][j] = false;
			}
		}
		//fill(visited.begin(), visited.end(), 0);
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
