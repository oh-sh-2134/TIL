#include<iostream>
#define MAX 100
#define COST_MAX 10004
using namespace std;

int appInfo[2][MAX];
int dp[COST_MAX];
int n, m;

int max(int a, int b) {
	return a > b ? a : b;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> appInfo[1][i];
	
	
	for (int i = 0; i < n; i++) 
		cin >> appInfo[0][i];
	
	
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = COST_MAX - 1; j >= appInfo[0][i]; j--) {
			dp[j] = max(dp[j], dp[j - appInfo[0][i]] + appInfo[1][i]);
		}
	}
	for (int i = 0; i < COST_MAX; i++) {
		if (dp[i] >= m) {
			cout << i;
			return;
		}
	}

}
int main(void) {
	input();
	solution();
}