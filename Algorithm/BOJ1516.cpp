#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int time[501];
int dp[501];
int buildingCnt[501];
vector<int> building[501];

int max(int a, int b) { return a > b ? a : b; }

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> time[i];
		dp[i] = time[i];
		while (true) {
			cin >> x;
			if (x == -1) break;
			else {
				building[x].push_back(i);
				buildingCnt[i]++;
			}
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (buildingCnt[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < building[cur].size(); i++) {
			int next = building[cur][i];
			dp[next] = max(dp[next], dp[cur] + time[next]);
			buildingCnt[next]--;
			if (buildingCnt[next] == 0)
				q.push(next);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << dp[i] << "\n";
}

//https://www.acmicpc.net/problem/1516
//위상정렬 이용