/*
#include<iostream>
#include<queue>
#define MAX 500

using namespace std;
int load[MAX][MAX];
int dp[MAX][MAX];
int N, M;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int max(int a, int b) {
	return a > b ? a : b;
}

int solution() {
	int cnt = 0;
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!(nx > 0 || nx <= N || ny > 0 || ny <= M)) continue;
			if ((ny == M - 1) && (nx == N - 1)) {
				cnt++;
				continue;
			}
			if (load[y][x] > load[ny][nx]) {
				q.push(make_pair(ny, nx));
				dp[ny][nx] = dp[y][x];
			}
		}
	}
	return cnt;
}

void Input() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> load[i][j];
		}
	}
}
int main() {
	int sol;
	Input();
	sol = solution();
	cout << sol;
}
*/
#include<iostream>
#define MAX 501

using namespace std;
int load[MAX][MAX];
int dp[MAX][MAX];
int N, M;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int solution(int y, int x) {

	if (y == M-1 && x == N-1) 
		return 1;
	
	else if(dp[y][x] == -1){
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if(load[y][x]>load[ny][nx]){
				dp[y][x] += solution(ny,nx);
			}
		}
	
	}
	return dp[y][x];
}

void Input() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j]=-1;
			cin >> load[i][j];
		}
	}
}

int main() {
	int sol;
	Input();
	sol = solution(0,0);
	cout << sol;
}
//https://www.acmicpc.net/problem/1520
//제출시 바운더리에러나는 부분 해결필요...
//BFS로 해결하는 문제가 아닌 DFS로 해결해야하는 문제였음
//처음에 풀었던 BFS로 풀때는 갔던길을 재방문하는 일이 발생할 수 있는데 어처피 적은수를 찾아서 가기떄문에 크게 문제가 안될꺼라 생각했는데 시간초과가 나버림
//반면에 DFS로 풀면 재방문 할 일이 없기때문에 DP와 함께 사용해서 
