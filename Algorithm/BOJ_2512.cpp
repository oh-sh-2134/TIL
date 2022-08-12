#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k,n;
vector<int> arr;

void input() {
	int m;
	cin >> k ;
	for (int i = 0; i < k; i++) {
		cin >> m;
		arr.push_back(m);
	}
	cin >> n;
}

int getTotal(int mid) {
	int sum = 0;
	for (auto iter : arr) {
		if (iter > mid)
			sum += mid;

		else
			sum += iter;
	}
	return sum;
}

void solution() {
	//hi을 문제의 조건에서 주어진 최댓값을 사용하지 않기 위해 정렬
	sort(arr.begin(), arr.end());
	long long lo = 0, hi = arr.back();
	int sol;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (getTotal(mid) <= n) {
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
//https://www.acmicpc.net/problem/2512
