#include<iostream>

#define MAX 100001

using namespace std;

int midx;
int arr[MAX];
int DP[MAX];

int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	DP[0] = arr[0];
	midx = DP[0];
	for (int i = 1; i < n; i++) {
		DP[i] = max(DP[i - 1] + arr[i], arr[i]); //이전의 합에 현제의 수를 더했는데도 현제의 수가 크다면 전의 합을 모두 버리고
		midx = max(DP[i], midx);           //새로 시작할 수 있다.
	}
	cout << midx;
}
//https://www.acmicpc.net/problem/1912
//점심시간에 내가 생각했던 아이디어가 완벽하다고 생각했는데 막상 집에와서 확인해보니 빈틈이 있었다.
//처음에 생각했던 아이디어는 DP 문제이기때문에 한 사이클에 풀어져야 한다고 생각했고
//지금의 아이디어와 비슷했는데 놓쳤던 가장 큰 문제가 이전까지의 합이 현제의 수보다 작을때 버려야한다는 것을 체크하는 부분이
//핵심이라는 것을 못잡았다. 아이디어를 머리로만 생각하지 말고 손으로 써서 검증하는 연습을 하자.
