#include<iostream>
#include<queue>
#include<vector>
#define MAX 1001
using namespace std;

int N, M;
int PrerequisiteCnt[MAX];
int Prerequisite[MAX];
vector<int> v[MAX];

int max(int a, int b) { return a > b ? a : b; }

void Input() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		Prerequisite[b]++;
	}
}

void solution() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (Prerequisite[i] == 0) {
			q.push(i);
			PrerequisiteCnt[i]++;
		}
	}
		

	while (!q.empty()) {
		int current = q.front(); 
		q.pop();

		for (int next = 0; next < v[current].size(); next++) {
			if (--Prerequisite[v[current][next]] == 0) 
				q.push(v[current][next]);
			PrerequisiteCnt[v[current][next]] = max(PrerequisiteCnt[v[current][next]], PrerequisiteCnt[current] + 1);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << PrerequisiteCnt[i] << " ";
	}
}

int main(void) {
	Input();
	solution();
}
//https://www.acmicpc.net/problem/14567