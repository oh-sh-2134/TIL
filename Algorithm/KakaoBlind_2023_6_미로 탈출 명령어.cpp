#include <string>
#include <vector>

using namespace std;

string dist[4] = { "d", "l", "r", "u" };
int my[4] = { 1,0,0,-1 };
int mx[4] = { 0,-1,1,0 };
int maxY;
int maxX;

class Point {
public:
	Point(int _y, int _x) {
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
	int y;
	int x;
};

int calLeftDist(Point &p1, Point &p2) {
	return abs(p1.getY() - p2.getY()) + abs(p1.getX() - p2.getX());
}

bool dfs(Point &cur, Point &end, int left, string &answer) {
	if (left == 0) 
		return true;
	
	for (int i = 0; i < 4; i++) {
		Point nxt = Point(cur.getY() + my[i], cur.getX() + mx[i]);
		if (nxt.getY() > maxY || nxt.getY() < 1 || nxt.getX() > maxX || nxt.getX() < 1) continue;
		if (left < calLeftDist(nxt, end)) continue;
		//남은 거리를 만족한다면 사전순으로 정렬된 알파벳 우선으로 이동한다.
		answer += dist[i];
		if (dfs(nxt, end, left - 1, answer)) return true;
	}

	return false;
}

string getResult(Point &start, Point &end, int left) {
	//처리하지 않으면 31번 케이스에서 시간초과 발생
	int totalDist = left - calLeftDist(start, end);
	//이동 가능 거리 - start에서 end까지의 거리가 0이면 당연히 도달할 수 없다
	//이동 가능 거리 - start에서 end가 0이상이라면 이미 목표에 도달한 상태임 이때는 목표지점에서 알파벳 순서가 빠른순으로(d->u->d->u)
	//왕복해서 움직여야 하는데 움직일 수 있는 거리가 홀수라면 end에서 이동 후 돌아올 수 없다.
	if (totalDist < 0 || totalDist % 2 != 0)
		return "impossible";
	string s = "";
	dfs(start, end, left, s);
	return s;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
	maxY = n;
	maxX = m;
	Point start = Point(x, y);
	Point end = Point(r, c);
	string answer = getResult(start, end, k);
	return answer;
}

int main(void) {
	solution(3, 4, 2, 3, 3, 1, 5);
}
//https://school.programmers.co.kr/learn/courses/30/lessons/150365