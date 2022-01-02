#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 101

using namespace std;


int require_parts[MAX];
int degree[MAX];
vector <pair<int, int>>v[MAX];
vector <int> nomal_parts;

int N,M;
int X, Y, K;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> X >> Y >> K;
		v[X].push_back({ Y,K });
		degree[Y]++;
	}
}

void solution() {
	queue<int>q;
	q.push(N);
	require_parts[N] = 1;
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (v[current].empty())
			nomal_parts.push_back(current);

		for (int i = 0; i < v[current].size(); i++) {
			int parts_idx = v[current][i].first;
			int parts_cnt = v[current][i].second;
			require_parts[parts_idx] += require_parts[current] * parts_cnt;
			if (--degree[parts_idx] == 0)
				q.push(parts_idx);
		}
	}

	sort(nomal_parts.begin(), nomal_parts.end());

	for (int i = 0; i < nomal_parts.size(); i++) {
		cout << nomal_parts[i] << " " << require_parts[nomal_parts[i]]<<"\n";
	}
}

int main(void) {
	Input();
	solution();
}

//https://www.acmicpc.net/problem/2637