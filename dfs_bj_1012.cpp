#include<iostream>
#include<vector>
#define MAX 51

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int field[MAX][MAX];
bool visited[MAX][MAX];
int t, m, n, k;
void dfs(int y,int x) { //벌레가 옮겨 다닐 수 있는 배추를 찾는 함수
	if (visited[y][x]) return;
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!(nx < 0 || nx >= n || ny < 0 || ny >= m)) {
			if (!visited[ny][nx] && field[ny][nx] == 1) {
				dfs(ny, nx);
			}
		}
	}
	return;
}

int main(void) {
	int a, b,cnt;
	vector<int>v;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cnt = 0;
		cin >> n >> m >> k;
		for (int y = 0; y < k; y++) {
			cin >> b >> a;
			field[a][b] = 1;
		}
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				if (field[y][x] == 1 && !visited[y][x]) {
					dfs(y, x);
					cnt++;
				}
			}
		}
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) { // 여러번의 케이스가 있을 수 있으니 배열 초기화
				visited[y][x] = false;
				field[y][x] = 0;
			}
		}
		v.push_back(cnt); // 케이스의 max를 안알려줘서 벡터를 이용해서 카운팅 저장

	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]<<"\n";
	}

}
//https://www.acmicpc.net/problem/1012
//원트에 패스하니까 기분 좋다 헤헤
//재귀 dfs 써서 했음