#include<iostream>
#include<queue>

#define MAX 1001

using namespace std;
int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1, 0,0 };

char field[MAX][MAX];
int cnt[MAX][MAX][2];

int bfs() {
	queue<int> q; // q를 너무 많이 만들고 pair를 사용하는 방법을 공부해야 될 것 같음
	queue<bool>qb;
	q.push(0);
	q.push(0);
	qb.push(false);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		int x = q.front();
		q.pop();
		bool brk = qb.front();
		qb.pop();
		if (y == n - 1 && x == m - 1) return cnt[y][x][brk]+1;
		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];
	
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (field[ny][nx] == '0' &&  cnt[ny][nx][brk] == 0) { // 0인 길을 가는데 갔던길은 가지 않음
				cnt[ny][nx][brk] = cnt[y][x][brk] + 1;
				q.push(ny);
				q.push(nx);
				qb.push(brk);
			}
			if ((field[ny][nx] == '1') && !brk && cnt[ny][nx][true] == 0) { // 벽을 만났을때 한번 뚫고 갈 수 있는 경우
				cnt[ny][nx][true] = cnt[y][x][brk] + 1;
				q.push(ny);
				q.push(nx);
				qb.push(true);

			}
		}
	}
	return -1;
}
int main(void) {
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> field[y][x];
		}
	}
	cnt[0][0][1] = 1;
	cnt[0][0][1] = 1;
	cout << bfs();
}
//https://www.acmicpc.net/problem/2206
//bfs를 이용해서 품 
//그래프 input에 띄어쓰기 안되 있으면 char로 받거나 scanf로 받아야 하는데 생각없이하다가 한 시간날림
//벽을 뚫고 나가는 케이스와 그냥가는 케이스가 한 점에서 만날 수 있는 케이스를 고려해야 함
//3차원 배열으로 뚫고 지나간 것과 뚫고 지나가지 않은 케이스를 한 좌표에 모두 기록 아래의 반례가 해당 케이스
/* 반례
5 10
0000011000
1101011010
0000000010
1111111110
1111000000
오답 : -1, 18
정답 : 14
*/