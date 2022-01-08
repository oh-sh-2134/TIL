#include<iostream>
#include<vector>
#include<queue>
#define MAX 10001


using namespace std;

int N, M;
int sol;
int indegree[MAX];
int time[MAX];
vector<int> work[MAX];


void Input() {
	int a;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> time[i];
		cin >> M;
		while (M--) {
			cin >> a;
			indegree[i]++;
			work[a].push_back(i);
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
		sol += time[current];
		for (auto itor : work[current]) {
			int next = itor;
			if (--indegree[next] == 0)
				q.push(next);
		}
	}
}

int main(void) {
	Input();
	solution();
	cout << sol;
}