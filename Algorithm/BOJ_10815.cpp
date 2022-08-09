#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
vector<int> A;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		A.push_back(k);
	}
	sort(A.begin(), A.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		cout << (int)binary_search(A.begin(), A.end(), k) << " ";
	}
}

//https://www.acmicpc.net/problem/10815