#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<bool> visited;
int n;
int a, b;
int cnt;


void input() {
	cin >> n;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int p;
		cin >> p;
		arr.push_back(p);
	}
	for (int i = 0; i < b; i++) {
		int p;
		cin >> p;
		arr.push_back(p);
	}
	visited.resize(a + b, false);
}

void dfs(int cur) {
	if (cur > n) return;
	if (cur == n) {
		cnt++; 
		return;
	}
	for (int i = 0; i < a + b; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(arr[i]+cur);
		visited[i] = false;
	}
}

void solution() {
	for (int i = 0; i < a + b; i++) {
		visited[i] = true;
		dfs(arr[i]);
		visited[i] = false;
	}
	cout << cnt;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/2632