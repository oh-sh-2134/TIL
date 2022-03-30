#include<iostream>
#include<vector>
using namespace std;
int n, m;
int arr[100004];
int sum[100004];
vector<pair<int, int>> range;

void Input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	int s, e;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		range.push_back({ s,e });
	}
}

void solution() {
	vector<int> sol;
	for (auto iter : range) 
		cout << (sum[iter.second] - sum[(iter.first - 1)])<<"\n";
}


int main(void) {
	Input();
	solution();
	return 0;
}