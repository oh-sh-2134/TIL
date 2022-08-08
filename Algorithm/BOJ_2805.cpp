#include <iostream>
#include <vector>
using namespace std;

int n, m ;
vector<int> tree;

void input() {
	int k;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> k;
		tree.push_back(k);
	}
}

bool check(int mid) {
	long long sum = 0; 
	for (int i = 0; i < n; i++) {
		if (tree[i] > mid) sum += tree[i] - mid;
	}
	return sum >= m;
}

void solution() {
	long long lo = 0, hi = 2000000000;
	long long sol = 0;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		if (check(mid)) {
			sol = mid;
			lo = mid+1;
		}
		else {
			hi = mid-1;
		}
	}
	cout << sol;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/2805