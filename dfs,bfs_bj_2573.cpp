#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ice[301][301];
int check[301][301];
int n, m;
int cnt;

queue<int> q;

void push(int i, int j) { //빙산이 있는 좌표를 큐에 저장
	q.push(i);
	q.push(j);
}
bool dfs() { // dfs를 이용해서 빙산이 나누어지는 것을 체크
	bool visited[301][301] = {false,};
	int div=0;
	stack<int>s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j] > 0 && !visited[i][j]) { // 빙산이 존재하면서 방문하지 않은 좌표일때
				visited[i][j] = true;
				s.push(i);
				s.push(j);
				while (!s.empty()) {
					int x = s.top();
					s.pop();
					int y = s.top();
					s.pop();
						for (int c = 0; c < 4; c++) {
							int nx = x + dx[c];
							int ny = y + dy[c];
							if (!(nx < 0 || nx >= m || ny < 0 || ny >= n)) {
								if (ice[ny][nx] > 0 && !visited[ny][nx]) {
									visited[ny][nx] = true;
									s.push(y);
									s.push(x);
									s.push(ny);
									s.push(nx);

								}
							}
						}	
				}
				div++; // 빙산체크 조건을 한번 이상 타게되면 모든 빙산을 체크하기 때문에 
			}
			if (div>1) return true; // div가 2이상만되면 나누어진 것으로 확인하고 return
		}
	}
	return false;
}
void melt() { // 빙산을 한번에 녹여 주는 함수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			while (check[i][j] && ice[i][j]) {
				check[i][j]--;
				ice[i][j]--;
			}
			check[i][j] = 0; // check를 초기화 안해주면 다음에는 더 많이 녹임
		}
	}

}
int bfs() {
	while (!q.empty()) {
		int size = q.size()/2; // x,y를 큐에 한번에 넣어서 2개를 빼면 2를 나누어줘야함(실수한 부분)
		for (int c = 0; c < size; c++) {
			int y = q.front();
			q.pop();
			int x = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(!(nx<0 || nx>=m || ny<0 || ny>=n)){
					if (ice[y][x]>0 && ice[ny][nx] == 0) {
						check[y][x]++;
					}
				}
			}
			if (ice[y][x] > 0) {
				push(y, x);
			}
		}
		melt();
		if(!q.empty()) cnt++;
		if (dfs()) return cnt;	
	}
	return 0;

}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j] != 0) {
				push(i, j);
			}
		}
	}
	cout<<bfs();

}
//https://www.acmicpc.net/problem/2573
//이 문제는 정말 고민 많이하고 실수도 많이 했다
//핵심은 빙산이 하나씩 녹으면 안된다는 점이다. melt함수를 통해 얼음을 년차별로 한번에 녹여줘야 한다.
//혹시라도 잊어버리면 곤란하니 오늘부터는 모든 라인에 설명을 달아야겠다.