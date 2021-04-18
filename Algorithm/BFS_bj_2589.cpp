#include<iostream>
#include<queue>
#include<cstring>
#define MAX 50
using namespace std;

int dx[4] = { 1,-1,0,0};
int dy[4] = { 0,0,-1,1};

char map[MAX][MAX];
bool visited[MAX][MAX];
int n, m,maxtime;

int max(int a, int b) {
	return a > b ? a : b;
}
int bfs(int a, int b) {
	int time = 0;
	queue<pair<int, int>>q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int qcnt = q.size();
		// 각섬에서 다음 섬을 선정하기 위해서는 큐에 쌓인 현제 섬을 모두 털어버려야 하기때문에 
		// 큐가 비워질때마다 다음섬으로 이동하는 것으로 판단하고 큐가 비워질때마다 카운팅
		for (int i = 0; i < qcnt; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
				if (map[nx][ny] == 'L' && !visited[nx][ny]) {
						q.push(make_pair(nx, ny));
						visited[nx][ny] = true;
				}
				
			}
		}
		time++;
	}
	return time-1;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				visited[i][j] = true;
				maxtime = max(bfs(i, j), maxtime);
				memset(visited, false, sizeof(visited));
			}
		}
	}
	cout << maxtime;
}
//https://www.acmicpc.net/problem/2589
//모든 map을 돌면서 최대의 거리가 나오는 곳을 체크하여 maxtime으로 저장하면 됨