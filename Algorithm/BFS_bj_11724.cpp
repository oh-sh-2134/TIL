#include<iostream>
#include<queue>
#define MAX 1001

using namespace std;
int n, m,cnt,s,d;
int field[MAX][MAX];
bool visted[MAX];
void dfs(int a) {
	visted[a] = true;
	for (int i = 1; i <= n; i++) {
		if (field[a][i] && !visted[i])
			dfs(i);
		if (i == n) return;
	}		
}
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s >> d;
		field[s][d] = 1;
		field[d][s] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!visted[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
}
//https://www.acmicpc.net/problem/11724
//오랜만에 bfs를 복습겸 풀었음 노드의 간선연결을 vector로 하지않고 2차원배열로 선언해서 풀었음
//dfs로 연결요소를 구하면 되는 간단한 문제