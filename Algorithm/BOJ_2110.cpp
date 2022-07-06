#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> home;
int n, c;

void input() {
	cin >> n >> c;
	while (n--) {
		int e;
		cin >> e;
		home.push_back(e);
	}
}

void solution() {
	int sol = 0;

	//이분탐색을 위한 정렬
	sort(home.begin(), home.end());

	//최소거리
	int start = 1; 
	//최대거리
	int end = home[home.size() - 1];
	int d = 0;
	while(start <= end) {
		int mid = (start + end) / 2;
		int pre = home[0];
		int cnt = 1;


		for (int i = 1; i < home.size(); i++) {
			if (home[i] - pre >= mid) {
				pre = home[i];
				cnt++;
			}
		}

		//공유기의 개수가 많을때
		if (cnt >= c) {
			sol = mid;
			start = mid + 1;
			continue;
		}

		//공유기의 개수가 부족할때
		end = mid - 1;

	}

	cout << sol;
}

int main() {
	input();
	solution();
}
//https://www.acmicpc.net/problem/2110