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
queue<Point> water;
queue<Point> newWater;
queue<Point> next;
queue<Point> newnext;
Point swan;

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
				swan = Point(i, j);
			}
			else if (field[i][j] != 'X') {
				water.push(Point(i, j));
			}
		}
	}
}

void meltIce() {
	while (!water.empty()) {
		Point p = water.front();
		water.pop();
		for (int i = 0; i < 4; i++) {
			int y = p.y + my[i];
			int x = p.x + mx[i];
			if (y >= R || y < 0 || x >= S || x < 0) continue;
			if (field[y][x] == 'X') {
				field[y][x] = '.';
				break;
			}
		}
	}
}

bool findSwan(Point p) {
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
			if (field[y][x] == 'X') {
				newnext.push(Point(y, x));
				continue;
			}
			if (field[y][x] == 'L') return true;
			visited[y][x] = true;
			q.push(Point(y, x));
		}


	}
	return false;
}

void solution() {
	while (true) {		
		if (findSwan(swan)) break;		
		meltIce();
		next = newnext;
		water = newWater;
		newnext = queue<Point>();
		newWater = queue<Point>();
		days++;
	}
	cout << days;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/3197
