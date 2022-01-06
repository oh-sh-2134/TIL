#include<iostream>
#include<queue>
#include<vector>
#define MAX 1001
using namespace std;

int indegree[MAX];
vector<int> adj[MAX];
vector<int> ans;

int n, m;

void Input() {
	bool flag = false;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cnt;
		int previous = 0;
		int input = 0;
		cin >> cnt >> previous;
		
		while(--cnt){
			cin >> input;
			adj[previous].push_back(input);
			indegree[input]++;
			previous = input;
		}
	}
}

void solution() {
	queue<int>q;
	int cnt = 0;
	for (int i = 1; i <= n; i++) 
		if (!indegree[i])
			q.push(i);

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		ans.push_back(current);
		
		for (auto iter : adj[current]) {
			int next = iter;
			if (--indegree[next] == 0)
				q.push(next);
		}
	}

	if (ans.size() != n) {
		ans.clear();
		ans.push_back(0);
	}
	for (auto iter : ans)
		cout << iter << "\n";
}


int main(void) {
	Input();
	solution();
}

//참고
//https://www.acmicpc.net/board/view/38847

/*
반례 
4 3
2 1 2
2 3 4
2 4 3


3 2
2 2 3
3 2 3 1

*/
