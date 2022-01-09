#include<iostream>
#include<vector>
#include<queue>
#define MAX 10001


using namespace std;

int N, M;
int sol;
int indegree[MAX];
int time[MAX];
vector<pair<int,int>> work[MAX];

int max(int a, int b) {	return a > b ? a : b; }

void Input() {
	int a;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> time[i];
		cin >> M;
		while (M--) {
			cin >> a;
			indegree[i]++;
			work[a].push_back({ i,time[i] });
		}
	}
}

void solution() {
	queue<int>q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i]==0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		sol = max(sol, time[current]);
		for (auto itor : work[current]) {
			int next = itor.first;
			int next_time = itor.second;
			time[next] = max(time[next], time[current] + next_time);

			if (--indegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main(void) {
	Input();
	solution();
	cout << sol;
}
/*
1번 반례
작업의 우선순의가 없을때
7
5 0
3 0
6 0
1 0
8 0
4 0
2 0
8

2번 반례
큐에 넣기전에 max 비교를 하게되면 이전 작업이 오래 걸리는 케이스에서 문제발생함
5
6 0
3 0
3 2 1 2
1 1 1
1 2 3 4

*/
