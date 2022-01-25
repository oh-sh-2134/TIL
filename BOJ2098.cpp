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

//visit �湮�� ���ÿ� ���� ��Ʈ ����ŷ
//current �̹��� ���� ����
int TSP(int visit, int current) {

	//current�� ���� �湮 �߰� 
	visit |= (1 << current);

	if (visit == (1 << n) - 1) {
		if (arr[current][0]) {
			return arr[current][0];
		}
		return INF;
	}


	//dp ���� ����
	if (dp[visit][current] > 0)
		return dp[visit][current];
	dp[visit][current] = INF;

	for (int i = 0; i < n; i++) {

		//current -> ���� �湮���� ���� i�� ���� ���� ��ΰ� �ִ� ���
		if (i != current && (visit&(1 << i)) ==0 && arr[current][i] > 0) { 

			//�ּ� ��� ����
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