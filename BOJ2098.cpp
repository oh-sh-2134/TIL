#include<iostream>
#define INF 987654321
#define MAX 16

using namespace std;

int dp[1 << MAX][MAX];
int arr[MAX][MAX];
int n;
void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

//visit 방문한 도시에 대한 비트 마스킹
//current 이번에 지날 도시
int TSP(int visit, int current) {

	//current번 도시 방문 추가 
	visit |= (1 << current);

	if (visit == (1 << n) - 1) {
		if (arr[current][0]) {
			return arr[current][0];
		}
		return INF;
	}


	//dp 개념 적용
	if (dp[visit][current] > 0)
		return dp[visit][current];
	dp[visit][current] = INF;

	for (int i = 0; i < n; i++) {

		//current -> 아직 방문하지 않은 i번 도시 가는 경로가 있는 경우
		if (i != current && (visit&(1 << i)) ==0 && arr[current][i] > 0) { 

			//최소 비용 갱신
			int temp = TSP(visit, i) + arr[current][i];
			if (dp[visit][current] > temp)
				dp[visit][current] = temp;

		}
	}
	return dp[visit][current];
}

void solution() {
	int sol = TSP(0, 0);
	cout << sol;
}

int main(void) {
	Input();
	solution();
}
//https://www.acmicpc.net/problem/2098