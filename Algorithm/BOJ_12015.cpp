#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<int> v;
void input() {
	cin >> n;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		arr.push_back(k);
	}
}

int lowerBound(int idx, int val) {
	int lo = 0, hi = idx;
	int rst = idx;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (v[mid] >= val) {
			lo = mid - 1;
			rst = mid;
		}
		else {
			hi = mid + 1;
		}
	}
	return rst;
}
void solution() {
	for (int i = 0; i < n; i++) {
		if (v.empty()) { 
			v.push_back(arr[i]); 
			continue; 
		}
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
		}
		else {
			v[lowerBound(v.size()-1, arr[i])] = arr[i];
		}
	}
	cout << v.size();

}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/12015