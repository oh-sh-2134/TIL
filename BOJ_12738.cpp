#include <iostream>
#include <vector>
#include<algorithm>
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
			hi = mid - 1;
			rst = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return rst;
}
void solution() {
	v.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
		}
		else {
			//lower_bound 사용 가능
			//*lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
			v[lowerBound(v.size() - 1, arr[i])] = arr[i];
		}
	}
	cout << v.size();

}

int main(void) {
	input();
	solution();
}