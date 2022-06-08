#include<vector>
#include<queue>
using namespace std;

int n;
int m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[100][100];

class point {
public :
	int x;
	int y;

	point(int a, int b) {
		y = a;
		x = b;
	}
};
int max(int a, int b) {
	return a > b ? a : b;
}
int solution(vector<vector<int> > maps)
{
	int answer = -1;
	vector<vector<int>> dist(maps.size(), vector<int>(maps[0].size(), 10004));
	vector<vector<bool>>visited(maps.size(), vector<bool>(maps[0].size(), false));
	n = maps.size();
	m = maps[0].size();
	queue<point> q;
	q.push(point(0, 0));
	dist[0][0] = 1;
	visited[0][0] = true;
	while (!q.empty()) {
		point p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int y = p.y + dy[i];
			int x = p.x + dx[i];
			if (y >= n || y < 0 || x >= m || x < 0) continue;
			if (maps[y][x] == 0) continue;
			if (dist[y][x] < dist[p.y][p.x] + 1) continue;
			if (visited[y][x]) continue;
			visited[y][x] = true;
			dist[y][x] = dist[p.y][p.x] + 1;
			q.push(point(y, x));
		}
	}
	if (dist[n - 1][m - 1] != 10004)
		answer = dist[n - 1][m - 1];
	return answer;
}

int main(void) {
	vector<vector<int>> v = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
	solution(v);
}