#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Point {
public:
	int x, y;
	Point(int a, int b) {
		y = a;
		x = b;
	}
	Point() {}
};

int t,h,w;
vector<vector<char>> map;
vector<Point> prisoner;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };


void input() {
	cin >> h >> w;
	//상근이가 접근할 테두리 만들어야 하기 때문에 +2
	map = vector<vector<char>>(h+2, vector<char>(w+2, '.'));
	prisoner.clear();
	for (int i = 1; i <= h ; i++) {
		for (int j = 1; j <=w; j++) {
			cin >> map[i][j];
			if (map[i][j] == '$') {
				prisoner.push_back(Point(i, j));
			}
		}
	}
}

// char map을 각 공간에 도착하기 위해 열어야 하는 문의 개수로 int map을 만들어야 함
// 특정 지점부터 BFS를 이용하여 벽일경우만 빼고 모두 탐색하여 문의 개수를 기록
// p는 상근, 죄수1, 2의 위치를 의미하며 BFS가 시작되는 지점임
vector<vector<int>> convertChar2Int(Point p) {
	int n = map.size();
	int m = map[0].size();
	vector<vector<int>> result(n, vector<int>(m, -1));
	result[p.y][p.x] = 0; // BFS의 시작점은 문일 수 없기 때문에 0시작
	deque<Point> dq; // 노드간 가중치가 0또는 +1이기 때문에 최소한으로 문을 통과한 노드를 먼저 탐색하기 위해 deque사용
	dq.push_front(p);
	while (!dq.empty()) {
		Point cur = dq.front();
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			Point next(cur.y + dy[i], cur.x + dx[i]);
			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m)continue;
			if (map[next.y][next.x] == '*') continue;
			if (result[next.y][next.x] > -1) continue;
			if (map[next.y][next.x] == '#') {
				result[next.y][next.x] = result[cur.y][cur.x] + 1;
				dq.push_back(next); //문을 통과한 지점은 +1 가중치를 가지는데 문을 통과한 최솟값을 구해야 하기 때문에 뒤쪽으로 넣어줌
			}
			else {
				result[next.y][next.x] = result[cur.y][cur.x];
				dq.push_front(next);//문을 통과하지 않은 지점은 가중치를 가지지 않기 때문에 앞으로 넣어줌
			}

		}
	}
	return result;
}

void solution() {
	vector<vector<int>> intMap1 = convertChar2Int(Point(0, 0));     //상근이의 int map
	vector<vector<int>> intMap2 = convertChar2Int(prisoner.front());//죄수1의 int map
	vector<vector<int>> intMap3 = convertChar2Int(prisoner.back());//죄수2의 int map

	//상근 죄수1, 죄수 2가 만날 수 있는 공간까지 열어야 하는 문의 개수를 구함
	int sol = 987654321;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (map[i][j] == '*') continue;
			if (intMap1[i][j] == -1 || intMap2[i][j] == -1 || intMap3[i][j] == -1) continue; //60%에서 막힘 아래반례
			int temp = intMap1[i][j] + intMap2[i][j] + intMap3[i][j]; // 세명이 모두 만나는 지점까지 열린 문의 개수
			if (map[i][j] == '#') temp -= 2; // 문에서 만날 경우 상근, 죄수1, 죄수2 모두가 문을 열기 때문에 2명의 카운트를 빼야함
			if (sol > temp) sol = temp;
		}
	}
	cout << sol << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		input();
		solution();
	}
}
//https://www.acmicpc.net/problem/9376
/*
1
3 5
*****
#$∗$#
*****

정답 : 2
*/