#include <iostream>
#include <vector>


using namespace std;

int n, m;
vector<int> arr;

void input() {
	cin >> n >> m;
	arr = vector<int>(m);
	for (int i = 0; i < m; i++)
		cin >> arr[i];
}

int solution() {
	int answer = 0;
	auto cmax = [](int a, int b) {return a > b ? a : b; };
	auto cmin = [](int a, int b) {return a > b ? b : a; };
	//열단위로 구해서 더해야함
	for (int i = 1; i < m - 1; i++) {
		int l = 0; int r = 0;
		//left 최대
		for (int j = 0; j < i; j++) l = cmax(l, arr[j]);
		//right 최대
		for (int j = m - 1; j > i; j--) r = cmax(r, arr[j]);
		answer += cmax(0, cmin(l, r) - arr[i]);
	}
	return answer;
}

int main() {
	input();
	cout << solution();
}
//https://www.acmicpc.net/problem/14719