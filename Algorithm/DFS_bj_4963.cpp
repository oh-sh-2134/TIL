#include<iostream>
#include<queue>
#define MAX 51

using namespace std;

int land[MAX][MAX];
int n, m, cnt;;

int dx[8] = { 1,-1,0,0,1,1,-1,-1};
int dy[8] = { 0,0,-1,1,1, -1,1,-1};
//대각선이 있어서 8개로 줘야함
void dfs(int x,int y) {
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!(nx > 0 || nx<=n || ny >0 || ny <= m)) continue; //범위를 벗어나면 
			if (land[nx][ny]) {
				land[nx][ny] = 0;
				q.push(make_pair(nx, ny));
			}
		}
	}

}
int main(void) {
	while (1) {
		cin >> n >> m;
		if (n + m == 0)break;
		cnt = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> land[i][j];
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (land[i][j]){
					land[i][j] = 0;
					dfs(i,j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}
//https://www.acmicpc.net/problem/4963
//섬의 위치를 1과 0으로 주기때문에 따로 방문처리를 위한 visted배열을 선언하지 않고
//ladn 배열로 한번에 처리해렸고 배열 초기화도 방문하면서 0으로 바꿔주기때문에 따로 하지 않아도 됨 