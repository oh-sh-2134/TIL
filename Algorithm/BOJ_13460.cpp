#include <iostream>
#include <vector>
#include <queue>
#define MAX 10
using namespace std;

int mx[4] = { 0,1,0,-1 };
int my[4] = { 1,0,-1,0 };
int ry, rx, by, bx;
bool visited[10][10][10][10];
int n, m;

vector<vector<char>> field;

//dirction
enum {
	up = 0,
	right = 1,
	down = 2,
	left = 3
};

//field element
enum {
	Wall = '#',
	Hole = 'O',
	Red = 'R',
	Blue = 'B',
	None = '.'
};

//구슬
class Bead {
private:
	int y;
	int x;
	int dirCnt;
public:
	Bead() {}
	Bead(int a, int b , int c) {
		y = a;
		x = b;
		dirCnt = c;
	}

	//방향만 받아서 움직일수 있을때까지 움직임
	int move(int dir) {
		int moveCnt = 0;
		while (true) {
			if (field[y][x] == Hole) break;
			char next = field[y + my[dir]][x + mx[dir]];
			if (next != None && next != Hole) break;
			y += my[dir];
			x += mx[dir];
			moveCnt++;
			
		}
		dirCnt++;
		return moveCnt;
	}	


	int getDircCnt() {
		return dirCnt;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};


void setField() {
	field = vector<vector<char>>(n, vector<char>(m, ' '));
}

void input() {
	cin >> n >> m;
	setField();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			if (field[i][j] == Red) {
				ry = i;
				rx = j;
				field[i][j] = None;
			}
			else if (field[i][j] == Blue) {
				by = i;
				bx = j;
				field[i][j] = None;
			}

		}
	}
}

void bfs() {
	queue<pair<Bead, Bead>> q;
	q.push({ Bead(ry,rx,0),Bead(by,bx,0) });
	visited[ry][rx][by][bx] = true;
	while (!q.empty()) {
		Bead red = q.front().first;
		Bead blue = q.front().second;
		q.pop();

		if (red.getDircCnt() > 9) break;

		for (int i = 0; i < 4; i++) {
			Bead r = red;
			Bead b = blue;
			int rMove = r.move(i);
			int bMove = b.move(i);

			//파란구슬이 먼저 들어가면 처리하지 않음
			if (field[b.getY()][b.getX()] == Hole) continue;
			if (field[r.getY()][r.getX()] == Hole) {
				cout << r.getDircCnt();
				return;
			}

			//두 구슬이 곂쳐질때
			if (r.getY() == b.getY() && r.getX() == b.getX()) {

				//이동 거리가 더 많은 구슬이 한칸 반대로 움직임
				if (rMove > bMove) {
					r = Bead(r.getY() - my[i], r.getX() - my[i], r.getDircCnt());
				}
				else {
					b = Bead(b.getY() - my[i], b.getX() - my[i], b.getDircCnt());
				}
			}
			
			if (visited[r.getY()][r.getX()][b.getY()][b.getX()]) continue;
			visited[r.getY()][r.getX()][b.getY()][b.getX()] = true;
			q.push({ r,b });

		}
	}
	cout << "-1";
}

void solution() {
	bfs();
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/13460
