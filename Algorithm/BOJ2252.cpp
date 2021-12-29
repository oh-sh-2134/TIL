#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M;
int num[32001];
vector<int> v[32001];

void Input() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		num[b]++;
	}
}

void solution() {
	queue<int> current;
	for (int i = 1; i <= N; i++)
		if (num[i] == 0) current.push(i);

	while (!current.empty()) {
		int i = current.front(); current.pop();
		cout << i << " ";

		for (int j = 0; j < v[i].size(); j++)
			if (--num[v[i][j]] == 0)
				current.push(v[i][j]);
	}
}

int main(void) {
	Input();
	solution();
}
//https://www.acmicpc.net/problem/2252
//위상정렬