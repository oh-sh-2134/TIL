#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<queue>


using namespace std;


int n, m;
map<string, vector<string>> adj;
map<string, pair<int,double>> lineage;
string kingName;
vector<string>wantKing;

void init(string name) {
	if (lineage.find(name) == lineage.end())
		lineage[name] = { 0 ,0 };
}

void Input() {
	cin >> n >> m;
	cin >> kingName;

	while (n--) {
		string parnt1, parnt2;
		string name;

		cin >> name >> parnt1 >> parnt2;
		init(name);
		init(parnt1);
		init(parnt2);
		adj[parnt1].push_back(name);
		adj[parnt2].push_back(name);
		lineage[name] = { 2,0 };
	}
	while (m--) {
		string name;
		cin >> name;
		wantKing.push_back(name);
	}
	lineage[kingName] = { 0,1 };
}

void solution() {
	queue<string>q;
	string nextking;
	double bloodBalance = 0;

	for (auto iter : lineage) {
		if (iter.second.first == 0)
			q.push(iter.first);
	}

	while (!q.empty()) {
		string current = q.front();
		q.pop();

		for (auto iter : adj[current]) {
			string next = iter;
			lineage[next].second += lineage[current].second;
			if (--lineage[next].first == 0) {
				q.push(next);
				lineage[next].second /= 2;
			}
		}
	}
	for (auto iter : wantKing) {
		if (bloodBalance < lineage[iter].second) {
			bloodBalance = lineage[iter].second;
			nextking = iter;
		}
	}
	cout << nextking;
}

int main(void) {
	Input();
	solution();
}

//https://www.acmicpc.net/problem/5021
//위상정렬 풀이