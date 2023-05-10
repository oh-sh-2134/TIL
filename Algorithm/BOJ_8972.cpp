#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Pos {
public:
	Pos(int _y, int _x) {
		y = _y;
		x = _x;
	}
	Pos();
	int y, x;
};
int dy[10] = {0,-1,-1,-1,0,0,0,1,1,1};
int dx[10] = {0,-1,0,1,-1,0,1,-1,0,1};
int n, m;
vector<vector<char>> arr;
string cmd;
Pos jongduino;
unordered_map<Pos,int> crazyArduinos;

void input() {
	cin >> n >> m;
	arr = vector<vector<char>>(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'I') jongduino = Pos(i, j);
			else if (arr[i][j] == 'R') crazyArduinos[Pos(i, j)]++;
		}
	}
	cin >> cmd;
}

bool moveJongduino(int d) {
	arr[jongduino.y][jongduino.x] = '.';
	jongduino.y += dy[d];
	jongduino.x += dx[d];
	if (arr[jongduino.y][jongduino.x] == 'R') return false;
	return true;
}

bool moveCrazyArduinos() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'R') {
				int moveDir = 0;
				int minDist = 0x3f3f3f3f;
				for (int dir = 1; dir <= 9; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
					int dist = abs(nx - jongduino.x) + abs(ny - jongduino.y);
					if (minDist > dist) {
						moveDir = dir;
						minDist = dist;
					}
				}
				int nx = i + dx[moveDir];
				int ny = j + dy[moveDir];
				if (arr[nx][ny] == 'I') return false;
				if (crazyArduinos[Pos(i, j)]) crazyArduinos[Pos(i, j)]--;
				crazyArduinos[Pos(i, j)]++;
			}
		}
	}
	for (auto &arduino : crazyArduinos) {
		if (arduino.second < 2) continue;
		crazyArduinos.erase(arduino.first);
	}
	return true;
}

void freshMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = '.';
		}
	}
	arr[jongduino.y][jongduino.x] = 'I';
	for (auto &arduino : crazyArduinos) {
		arr[arduino.first.y][arduino.first.x] = 'R';
	}
}

void solution() {
	for (int i = 0; i < cmd.size(); i++) {
		int dirc = cmd[i] - '0';
		if (moveJongduino(dirc) && moveCrazyArduinos()) continue;
		cout << "kraj " << i + 1; 
		return; 		
	}
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/8972