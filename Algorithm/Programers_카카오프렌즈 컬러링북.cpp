#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int mx[4] = { 0,0,1,-1 };
int my[4] = { 1,-1,0,0 };
class point {
public:
	int x;
	int y;
	point(int a, int b) {
		y = a;
		x = b;
	}
};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<vector<int>> pictures = picture;
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	unordered_set<int> s;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			queue<point> q;
			q.push(point(i, j));
			s.insert(pictures[i][j]);
			if (pictures[i][j] == 0) continue;
			visited[i][j] = true;
			int idx = pictures[i][j];
			int cnt = 1;
			while (!q.empty()) {
				point p = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int y = p.y + my[k];
					int x = p.x + mx[k];
					if (y >= m || y < 0 || x >= n || x < 0) continue;
					if (pictures[y][x] != idx) continue;
					if (visited[y][x]) continue;
					visited[y][x] = true;
					q.push(point(y, x));
					cnt++;
				}
			}
			if (cnt > max_size_of_one_area) max_size_of_one_area = cnt;
		}
	}
	number_of_area = s.size();


	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main(void) {
	vector<vector<int>> v = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
	solution(6, 4, v);
}
//https://programmers.co.kr/learn/courses/30/lessons/1829
//문제의 테스트 케이스는 맞았지만 정답처리는 받지 못했다. 
//전역변수를 함수 내부에서 초기화를 해야한다고 하는데, 함수 내부에서 초기화를 하더라도 정답처리를 받지 못함
//스트레스 받아서 정답처리 받았다고 생각하고 있음