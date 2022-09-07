#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> line;
vector<int> highest;
vector<int> lowest;
int n;

void solution() {
	cin >> n;
	line.resize(3,0);
	highest.resize(3,0);
	lowest.resize(3,0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> line[j];
		}
		if (i == 0) {
			highest = line;
			lowest = line;
			continue;
		}
		// 0 과 1, 1과 2에서 얻어낸 최댓값들을 비교하여 얻는 최댓값은 0, 1, 2의 최댓값이 됨
		highest[0] = max(highest[0], highest[1]);
		highest[2] = max(highest[1], highest[2]);
		highest[1] = max(highest[0], highest[2]) + line[1];
		highest[0] += line[0];
		highest[2] += line[2];

		lowest[0] = min(lowest[0], lowest[1]);
		lowest[2] = min(lowest[1], lowest[2]);
		lowest[1] = min(lowest[0], lowest[2]) + line[1];
		lowest[0] += line[0];
		lowest[2] += line[2];
	}
	cout << max(max(highest[0], highest[1]), highest[2]) << " " << min(min(lowest[0], lowest[1]), lowest[2]);
}


int main(void) {
	solution();
}
//https://www.acmicpc.net/problem/2096