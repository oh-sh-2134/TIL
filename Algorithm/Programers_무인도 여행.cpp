#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int mx[4] = { 0,0,1,-1 };
int my[4] = { 1,-1,0,0 };
vector<vector<char>> charMap;
vector<vector<bool>> visited;

int bfs(int _y, int _x) {
	int sum = charMap[_y][_x] - '0';
	visited[_y][_x] = true;
	queue<pair<int, int>> q;
	q.push({ _y,_x });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = y + my[i];
			int dx = x + mx[i];
			if (dy >= n || dy < 0 || dx >= m || dx < 0) continue;
			if (visited[dy][dx]) continue;
			visited[dy][dx] = true;
			if (charMap[dy][dx] == 'X') continue;
			sum += charMap[dy][dx] - '0';
			q.push({ dy,dx });
		}
	}
	return sum;
}

vector<int> solution(vector<string> maps) {
	n = maps.size();
	m = maps[0].length();
	charMap = vector<vector<char>>(n, vector<char>(m));
	visited = vector<vector<bool>>(n, vector<bool>(m, false));
	vector<int> answer;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			charMap[i][j] = maps[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (charMap[i][j] == 'X') continue;
			if (visited[i][j]) continue;
			answer.push_back(bfs(i, j));
		}
	}
	sort(answer.begin(), answer.end());
	if (answer.size() == 0) answer.push_back(-1);

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/154540