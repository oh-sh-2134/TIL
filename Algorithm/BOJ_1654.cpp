#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, n;
vector<int> arr;

void input() {
	int m;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> m;
		arr.push_back(m);
	}
}

bool check(int mid) {
	long long cnt = 0;
	for (auto iter : arr) {
		cnt += iter / mid;
	}
	return cnt >= n;
}

void solution() {
	sort(arr.begin(), arr.end());
	long long lo = 1 , hi = arr.back();
	int sol = 0;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		if (check(mid)) {
			lo = mid + 1;
			sol = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << sol;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/1654
