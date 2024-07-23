#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

#define MAX 100001

using namespace std;

int V, E, nIdx, parentsMap[MAX];
bool visited[MAX];
vector<vector<int>> SCC;
vector<int> link[MAX];
stack<int> nodeStack;

int min(int a, int b) {
	return a > b ? b : a;
}

void input() {
	cin >> V >> E;
	int a, b;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		link[a].push_back(b);
	}
}

int dfs(int nodeNum) {
	parentsMap[nodeNum] = ++nIdx;
	nodeStack.push(nodeNum);
	int parent = parentsMap[nodeNum];
	for (int i = 0; i < link[nodeNum].size(); i++) {
		int nxt = link[nodeNum][i];
		if (parentsMap[nxt] == 0) parent = min(parent, dfs(nxt));
		else if (!visited[nxt]) parent = min(parent, parentsMap[nxt]);
	}
	if (parent == parentsMap[nodeNum]) {
		vector<int> scc;
		while (1) {
			int n = nodeStack.top();
			nodeStack.pop();
			scc.push_back(n);
			visited[n] = true;
			if (n == nodeNum) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return parent;
}



int main(void) {
	input();
	for (int i = 1; i <= V; i++) {
		if (visited[i]) continue;
		dfs(i);
	}
	sort(SCC.begin(), SCC.end());
	cout << SCC.size() << "\n";
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << " ";
		}
		cout << "-1\n";
	}
}
//https://www.acmicpc.net/problem/2150