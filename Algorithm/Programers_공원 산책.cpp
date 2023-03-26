#include <string>
#include <vector>

using namespace std;

class Point {
public:
	Point() {};
	void move(int _y, int _x) {
		y = _y;
		x = _x;
	}
	int getY() {
		return y;
	}
	int getX() {
		return x;
	}
private:
	int y = 0;
	int x = 0;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int dic2Idx(char c) {
	if (c == 'N') return 0;
	if (c == 'S') return 1;
	if (c == 'W') return 2;
	if (c == 'E') return 3;
}

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;
	Point cur;
	for (int i = 0; i < park.size(); i++) {
		for (int j = 0; j < park[i].size(); j++) {
			if (park[i][j] == 'S') { cur.move(i, j); break; }
		}
	}
	for (auto route : routes) {
		bool impassable;
		int a = route[2] - '0';
		int y = cur.getY();
		int x = cur.getX();
		for (int i = 0; i < (route[2] - '0'); i++) {
			impassable = true;
			y += dy[dic2Idx(route[0])];
			x += dx[dic2Idx(route[0])];
			if (y >= park.size() || y < 0 || x >= park[y].size() || x < 0) break;
			if (park[y][x] == 'X') break;
			impassable = false;
		}
		if (impassable) continue;
		cur.move(y, x);
	}
	answer.push_back(cur.getY());
	answer.push_back(cur.getX());
	return answer;
}

int main(void) {
	vector<string> s1 = { "OSO", "OOO", "OXO", "OOO" };
	vector<string> s2 = { "E 2", "S 3", "W 1" };
	solution(s1,s2);
}


//https://school.programmers.co.kr/learn/courses/30/lessons/172928