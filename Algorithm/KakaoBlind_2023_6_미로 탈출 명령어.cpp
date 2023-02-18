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
		//���� �Ÿ��� �����Ѵٸ� ���������� ���ĵ� ���ĺ� �켱���� �̵��Ѵ�.
		answer += dist[i];
		if (dfs(nxt, end, left - 1, answer)) return true;
	}

	return false;
}

string getResult(Point &start, Point &end, int left) {
	//ó������ ������ 31�� ���̽����� �ð��ʰ� �߻�
	int totalDist = left - calLeftDist(start, end);
	//�̵� ���� �Ÿ� - start���� end������ �Ÿ��� 0�̸� �翬�� ������ �� ����
	//�̵� ���� �Ÿ� - start���� end�� 0�̻��̶�� �̹� ��ǥ�� ������ ������ �̶��� ��ǥ�������� ���ĺ� ������ ����������(d->u->d->u)
	//�պ��ؼ� �������� �ϴµ� ������ �� �ִ� �Ÿ��� Ȧ����� end���� �̵� �� ���ƿ� �� ����.
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