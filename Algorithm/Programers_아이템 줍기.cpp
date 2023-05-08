#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define MAXSIZE 102

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<vector<int>> board;
vector<vector<int>> dist;

class Point {
public:
	Point();
	Point(int _x, int _y) {
		y = _y;
		x = _x;
	}
	int y;
	int x;
};
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	board = vector<vector<int>>(MAXSIZE, vector<int>(MAXSIZE, 0));
	dist = vector<vector<int>>(MAXSIZE, vector<int>(MAXSIZE, -1));

	//rectangle 전체 마킹
	for (auto rect : rectangle) {
		for (int i = rect[1] * 2; i <= rect[3] * 2; ++i) {
			for (int j = rect[0] * 2; j <= rect[2] * 2; ++j) {
				board[i][j] = 1;
			}
		}
	}

	//rectangle 내부 마킹 제거
	for (auto rect : rectangle) {
		for (int i = rect[1] * 2 + 1; i < rect[3] * 2; ++i) {
			for (int j = rect[0] * 2 + 1; j < rect[2] * 2; ++j) {
				board[i][j] = 0;
			}
		}
	}


	queue<Point> q;
	q.push(Point(characterY * 2, characterX * 2));
	dist[characterY * 2][characterX * 2] = 0;
	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= MAXSIZE || ny >= MAXSIZE) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == 0) continue;
			q.push(Point(nx, ny));
			dist[nx][ny] = dist[cur.x][cur.y] + 1;
		}
	}
	return dist[itemY * 2][itemX * 2] / 2;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/87694