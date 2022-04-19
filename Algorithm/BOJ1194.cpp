#include<iostream>
#include<queue>
#include <string>
using namespace std;

int n, m;
struct point
{
	int y = 0;
	int x = 0;
};
char arr[50][50];
point start;
bool visited[50][50][(1 << 6)];

int ny[4] = { 0,0,-1,1 };
int nx[4] = { 1,-1,0,0 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {					
			arr[i][j] = s[j];
			if (arr[i][j] == '0') {
				start.y = i;
				start.x = j;
			}
		}
	}
}


int bfs(int sY, int sX) {
	//<<y,x>,<cnt,state>>
	queue<pair<pair<int, int>, pair<int, int>> > q;
	q.push({ {sY,sX},{0,0} });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second.first;
		int state = q.front().second.second;
		q.pop();
		if (arr[y][x] == '1') return cnt;
		visited[y][x][state] = true;
		for (int i = 0; i < 4; i++) {
			int dy = y + ny[i];
			int dx = x + nx[i];
			//방문 체크
			if (visited[dy][dx][state]) continue;
			//범위 체크
			if (dy >= n || dy<0 || dx>=m || dx < 0) continue;
			//벽 체크
			if (arr[dy][dx] == '#') continue;
			//열쇠 획득
			if (arr[dy][dx] >= 'a' && arr[dy][dx] <= 'f') {
				//state를 아래와 같이 가져가면 for문을 돌면서 열쇠가 없는 상태로 방문을 열어야할때 이전 for문에 의해 열쇠가 있는 경우가 생김
				//state = state | (1 << (arr[dy][dx] - 'a'));
				int new_state = state | (1 << (arr[dy][dx] - 'a'));
				q.push({ { dy,dx }, { cnt + 1,new_state } });
				continue;
			}
			//열쇠 체크
			if (arr[dy][dx] >= 'A' && arr[dy][dx] <= 'F') {
				if ((state &  (1 << (arr[dy][dx] - 'A')))==0)
					continue;
			}
			q.push({ { dy,dx }, { cnt + 1,state } });
		}
	}
	return -1;
}

void solution() {
	cout << bfs(start.y, start.x);
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/1194