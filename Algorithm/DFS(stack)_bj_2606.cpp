#include<iostream>
#include<stack>
#include<vector>

using namespace std;


int visit[101];
vector<int> node[101];
int sol;

void dfs(int start) {
	stack<int>check;
	check.push(start);
	while (!check.empty()) {
		int current = check.top();
		check.pop();
		if (visit[current]) continue;
		visit[current] = true;
		sol++;
		for (int i = 0; i < node[current].size(); i++){
			int next = node[current][i];
			check.push(current);
			check.push(next);
		}

	}
	cout << sol-1;

}

void makenode(int a, int b) {
	node[a].push_back(b);
	node[b].push_back(a);
}

int main(void) {
	int N, K,a,b;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		makenode(a, b);
	}
	dfs(1);
}
//https://www.acmicpc.net/problem/2606
//dfs를 stack으로 구현하여 풀었음 
//바운더리 런타임에러 조심