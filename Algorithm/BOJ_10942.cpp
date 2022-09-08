#include <iostream>
#include <vector>

using namespace std;

int N, M, E, S;

vector<int> arr;
vector<vector<bool>> dp;

void solution() {
	cin >> N;
	arr.resize(N+1);
	dp.resize(N + 1, vector<bool>(N + 1, false));
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i][i] = true;		// 길이가 1일때		
	}
	for (int i = 1; i < N; i++) {
		if (arr[i] == arr[i + 1]) // 길이가 2일때
			dp[i][i + 1] = true;

	}
	for (int i = 2; i < N; i++) { //길이가 3이상일때
		for (int j = 1; j <= N - i; j++) {
			// 배열의 앞뒤가 같고 앞뒤 사이에 있는 수가 팰린드 수 일때
			if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1]) 
				dp[j][i + j] = true;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> E >> S;
		cout << dp[E][S] << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
}
//https://www.acmicpc.net/problem/10942