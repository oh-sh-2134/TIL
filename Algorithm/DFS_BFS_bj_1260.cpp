#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include <algorithm>
using namespace std;

int cd[1001];
int cb[1001];
vector<int>ad[1001];
vector<int>ab[1001];


void dfs(int start) {
	stack<int> stak;
	stak.push(start);
	while (!stak.empty()) {
		int current = stak.top();
		stak.pop();
		if (cd[current]) continue;
		cd[current] = true;
		cout << current<<" ";
		for (int i = ad[current].size() - 1; i >= 0; i--) {
			int next = ad[current][i];
			stak.push(current);
			stak.push(next);
		}
	}
}

void bfs(int start) {
	queue<int>q;
	cb[start] = true;
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < ab[x].size(); i++) {
			int y = ab[x][i];
			if (!cb[y]) {
				cb[y] = true;
				q.push(y);
			}
		}
	}
}

void maketree(int x, int y) {
	ad[x].push_back(y);
	ad[y].push_back(x);

	ab[x].push_back(y);
	ab[y].push_back(x);
}

int main(void) {
	int N, K, S;
	int x, y;
	cin >> N >> K >> S;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		maketree(x, y);
	}
	for (int i = 0; i < 1001; i++) {
		sort(ad[i].begin(), ad[i].end());
		sort(ab[i].begin(), ab[i].end());
	}
	dfs(S);
	cout << endl;
	bfs(S);
}

//https://www.acmicpc.net/problem/1260
// dfs, bfs 복습겸 다시 했는데 dfs를 스택으로 풀어봤음