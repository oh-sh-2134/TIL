#include<iostream>
#include<map>
#include<vector>
#include<string>


using namespace std;


int n, m;
map<string, vector<string>> adj;
map<string, double> lineage;
string kingName;
vector<string>wantKing;

void init(string name) {
	if (lineage.find(name) == lineage.end())
		lineage[name] = 0;
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
		adj[name].push_back(parnt1);
		adj[name].push_back(parnt2);
	}
	while (m--) {
		string name;
		cin >> name;
		wantKing.push_back(name);
	}
	lineage[kingName] = 1;
}

double dfs(string name) {
	if (lineage[name] != 0)
		return lineage[name];

	if (adj[name].empty())
		return lineage[name];

	return lineage[name] = (dfs(adj[name][0]) + dfs(adj[name][1])) / 2;
}

void solution() {
	string nextking;
	double bloodBalance = 0;
	for (auto iter : wantKing) {
		if (bloodBalance < dfs(iter)) {
			bloodBalance = dfs(iter);
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
//dfs Ç®ÀÌ