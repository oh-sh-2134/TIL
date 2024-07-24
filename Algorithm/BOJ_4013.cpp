#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
#include<queue>

#define MAX 500001

using namespace std;

int N, M, nIdx, startPoint, restoreCnt, maxCash;
int parentsMap[MAX], cashMap[MAX];
bool visited[MAX];
vector<vector<int>> SCC;
vector<int> link[MAX];
vector<int> sccLink[MAX];
stack<int> nodeStack;
unordered_map<int, bool> restoreMap;
unordered_map<int, bool> sccRestoreMap;
unordered_map<int,int> sccTotalCash;

int min(int a, int b) {
	return a > b ? b : a;
}

void input() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		link[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		cin >> a;
		cashMap[i] = a;
	}
	cin >> startPoint >> restoreCnt;
	for (int i = 0; i < restoreCnt; i++) {
		cin >> a;
		restoreMap[a] = true;
	}
}

int sccDfs(int nodeNum) {
	parentsMap[nodeNum] = ++nIdx;
	nodeStack.push(nodeNum);
	int parent = parentsMap[nodeNum];
	for (int i = 0; i < link[nodeNum].size(); i++) {
		int nxt = link[nodeNum][i];
		if (parentsMap[nxt] == 0) parent = min(parent, sccDfs(nxt));
		else if (!visited[nxt]) parent = min(parent, parentsMap[nxt]);
	}
	if (parent == parentsMap[nodeNum]) {
		vector<int> scc;
		int totalCash = 0;
		bool restore = false;
		while (1) {
			int n = nodeStack.top();
			nodeStack.pop();
			scc.push_back(n);
			parentsMap[n] = parent;
			visited[n] = true;
			totalCash += cashMap[n];
			cashMap[n] = 0;
			if (restoreMap[n])
				restore = true;
			if (n == nodeNum) break;
		}
		SCC.push_back(scc);
		sccTotalCash[parentsMap[nodeNum]] = totalCash;
		sccRestoreMap[parentsMap[nodeNum]] = restore;
	}
	return parent;
}

void makeSccDfs() {
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		sccDfs(i);
	}
}

void makeSccLink() {
	for (int i = 0; i <= N; i++) {
		for (auto w : link[i]) {
			if (parentsMap[w] == parentsMap[i]) continue;
			sccLink[parentsMap[i]].push_back(parentsMap[w]);
		}
	}
}

int max(int a, int b) {
	return a > b ? a : b;
}

void findMaxCash(int sccIdx ) {	
	queue<int> q;
	q.push(sccIdx);
	cashMap[q.front()] = sccTotalCash[q.front()];
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (sccRestoreMap[cur])
			maxCash = max(maxCash, cashMap[cur]);
		for (int i = 0; i < sccLink[cur].size(); i++) {
			int next = sccLink[cur][i];
			if (cashMap[next] >= cashMap[cur] + sccTotalCash[next]) continue;
			cashMap[next] = cashMap[cur] + sccTotalCash[next];
			q.push(next);
		}
	}
	
}

int main(void) {
	input();	
	makeSccDfs();
	makeSccLink();
	findMaxCash(parentsMap[startPoint]);
	cout << maxCash << "\n";

}
//https://www.acmicpc.net/problem/4013