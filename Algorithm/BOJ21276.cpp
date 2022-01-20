#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define MAX l001
using namespace std;

int n, m;

map<string, vector<string>> adj;
map<string, vector<string>> pedigree;

map<string, int> indegree;

vector<string> ancestor;
void Init(string name) {
	indegree[name] = 0;
}


void Input() {
	string name1,name2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name1;
		Init(name1);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> name1 >> name2;
		adj[name2].push_back(name1);
		indegree[name1]++;
	}

}

void topology_sort(string name) {
	queue<string> q;
	q.push(name);
	while (!q.empty()) {
		string current = q.front();
		q.pop();
		for (auto iter : adj[current]) {
			string next = iter;
			if (--indegree[next] == 0) {
				q.push(next);
				pedigree[current].push_back(next);

			}
		}
	}

}

void solution(){
	for (auto iter : indegree) {
		if (iter.second == 0) {
			ancestor.push_back(iter.first);
		}
	}
	cout << ancestor.size()<<"\n";
	for (auto iter : ancestor) {
		topology_sort(iter);
		cout << iter << " ";
	}
	cout << "\n";
	
	for (auto iter : indegree) {
		cout << iter.first << " " << pedigree[iter.first].size()<<" ";
		if (pedigree[iter.first].size())
			for (auto element : pedigree[iter.first])
				cout << element << " ";
		cout << "\n";
	}
}

int main(void) {
	Input();
	solution();
}
//https://www.acmicpc.net/problem/21276
//자신을 조상으로 하는 노드를 정렬할때 indegree간선이 0이되면 부모 노드가 됨