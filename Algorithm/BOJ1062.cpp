#include<iostream>
#include<vector>
#include<string>
#define MAX 26
using namespace std;

bool alpa[MAX];
int n, k;
int sol;
vector<string> str;

int max(int a, int b) {
	return a > b ? a : b;
}


void Input() {
	string s;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		str.push_back(s);
	}
	
}
void dfs(int current, int cnt) {
	if (cnt == 0) {
		int sCnt = 0;
		for (auto iter : str) {
			bool flag = true;
			for (int i = 4; i < iter.size() - 4; i++) {
				if (alpa[iter[i]-'a']) continue;
				flag = false;
				break;
			}
			if (flag)
				sCnt++;
		}
		sol = max(sol, sCnt);
	}
	for (int i = current; i < MAX; i++) {
		if (alpa[i]) continue;

		alpa[i] = true;
		dfs(i, cnt-1);
		alpa[i] = false;
	}
}
void solution() {
	int state = 0;
	vector<int> v;

	fill(alpa, alpa + MAX, false);
	alpa['a' - 'a'] = true;
	alpa['n' - 'a'] = true;
	alpa['t' - 'a'] = true;
	alpa['c' - 'a'] = true;
	alpa['i' - 'a'] = true;

	dfs(0, k-5);
	
}

int main(void) {
	Input();
	solution();
	cout << sol;
}
//https://www.acmicpc.net/problem/1062
/*
1 5
antatica
*/