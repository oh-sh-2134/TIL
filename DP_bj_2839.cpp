#include<iostream>
#include<queue>
#define MAX 5001

using namespace std;

int DP[MAX];
int n;
int cnt = 1;
int dx[2] = { 3, 5}; // 되돌아 갈필요가 없으니 -3, -5는 안넣어도 됨
void bfs() {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int qcnt = q.size();
		for (int i = 0; i < qcnt; i++) {
			int x = q.front();
			q.pop();
			for (int k = 0; k < 2; k++) {
				int nx = x + dx[k];
				if (nx > 0 && nx <= n && DP[nx] == 0) {
					DP[nx] = cnt;
					q.push(nx);
				}
			}

		}
		cnt++;
	}
}

int main(void) {
	cin >> n;
	bfs();
	if (DP[n] == 0)
		cout << "-1";
	else
		cout << DP[n];
	return 0;
}
//https://www.acmicpc.net/problem/2839
//다들 그리디로 푸는거 같은데 bfs와 dp로 품