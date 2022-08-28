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
queue<Point> nextWater;
queue<Point> area;
queue<Point> nextArea;

int mx[4] = { 0,0,1,-1 };
int my[4] = { 1,-1,0,0 };




void input() {
	cin >> R >> S;
	field = vector<vector<char>>(R, vector<char>(S, '.'));
	visited = vector<vector<bool>>(R, vector<bool>(S, false));
	Point swan;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			cin >> field[i][j];
			if (field[i][j] == 'L') {
				swan = Point(i, j);
			}
			if (field[i][j] != 'X') {
				water.push(Point(i, j));
			}
		}
	}
	area.push(swan);
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
				nextWater.push(Point(y, x));
				//break; 여기 때문에 5%에서 틀림 - https://www.acmicpc.net/board/view/94425
			}
		}
	}
}

bool findSwan() {
	while (!area.empty()) {
		Point cur = area.front();
		visited[cur.y][cur.x] = true;
		area.pop();
		for (int i = 0; i < 4; i++) {
			int y = my[i] + cur.y;
			int x = mx[i] + cur.x;
			if (y >= R || y < 0 || x >= S || x < 0) continue;
			if (visited[y][x]) continue;
			visited[y][x] = true;
			if (field[y][x] == 'X') {
				nextArea.push(Point(y, x));
			}
			else if (field[y][x] == '.') {
				area.push(Point(y, x));
			}
			if (field[y][x] == 'L') return true;
		}


	}
	return false;
}

void solution() {
	while (true) {		
		if (findSwan()) break;		
		meltIce();
		area = nextArea;
		water = nextWater;
		nextArea = queue<Point>();
		nextWater = queue<Point>();
		days++;
	}
	cout << days;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/3197
