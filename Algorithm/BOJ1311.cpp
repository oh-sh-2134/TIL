#include<iostream>
#define MAX 21
#define INF 987654321
using namespace std;

int n;
int task[MAX][MAX];
int state[MAX][(1 << 21)];

int min(int a, int b) {	return a > b ? b : a;}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> task[i][j];
}


int dfs(int current, int currentState) {
	//모든 수를 확인했을때
	if (currentState == ((1 << n) - 1)) return 0;

	//이미 값이 있다면
	if (state[current][currentState] != INF) return state[current][currentState];


	for (int i = 0; i < n; i++) {
		//처리한 task일 경우
		if (currentState & (1 << i)) continue;
		//모든 경우의 수를 확인
		state[current][currentState] = min(state[current][currentState], dfs(current + 1, currentState | (1 << i))+task[current][i]);
	}
	return state[current][currentState];
}

void solution() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < (1 << 21); j++) {
			state[i][j] = INF;
		}
	}
	cout << dfs(0,0);
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/1311