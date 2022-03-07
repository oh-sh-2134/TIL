#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, l, r, x;
vector<int> arr;
void Input() {
	cin >> n >> l >> r >> x;
	int sum;
	for (int i = 0; i < n; i++) {
		cin >> sum;
		arr.push_back(sum);
	}
}

void solution() {
	int cnt = 0;
	sort(arr.begin(), arr.end());
	for (int i = 1; i < (1 << n); i++) {
		int total = 0;
		vector<int> p;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) 
				p.push_back(arr[j]);					
		}
		if (p.size() < 2) continue;
		if (p[p.size()-1] - p[0] < x) continue;
		for (auto iter : p) 
			total += iter;
		
		if (total >= l && total <= r)
			cnt++;
	}
	cout << cnt;
}

int main(void) {
	Input();
	solution();
}
//https://www.acmicpc.net/problem/16938