#include<vector>
#include<iostream>

using namespace std;

int n, s;
vector<int> arr;

void input() {
	cin >> n >> s;
	arr = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int solution() {
	int answer = s + 1;
	int r = 0, l = 0, sum = arr[0];
	auto cmin = [](int a, int b) {return a > b ? b : a; };
	while (l<=r && r<n) {
		if (sum < s) {
			sum += arr[++r];
			continue;
		}
		answer = cmin(answer, r - l+1);
		sum -= arr[l++];
		
	}

	return answer == s + 1 ? 0 : answer;
}

int main(void) {
	input();
	cout << solution();
}
//https://www.acmicpc.net/problem/1806