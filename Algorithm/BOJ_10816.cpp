#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
vector<int> A;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	unordered_map<int, int > map;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		A.push_back(k);
		map[k]++;
	}
	sort(A.begin(), A.end());
	cin >> m;
	//이진탐색을 하지 않아도 정답을 받을 수 있음
	for (int i = 0; i < m; i++) {
		cin >> k;
		//if (binary_search(A.begin(), A.end(), k))
			cout << map[k] << " ";
		//else
			//cout << map[k];
	}
}

//https://www.acmicpc.net/problem/10816