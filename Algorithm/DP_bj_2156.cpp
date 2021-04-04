#include<iostream>
#include<algorithm>
#define MAX 10001

using namespace std;

int DP[MAX];
int arr[MAX];
int n;
int idx;
int getmax(int a, int b, int c) { // 3개의 와인을 마실경우 반드시 마지막의 와인을 마셔야하지 않음
	int idx[3] = { a,b,c };		  // 3개의 와인을 마시는 케이스일때 배열에 담아 sort했는데 아무 옵션도 주지 않으면
	sort(idx, idx + 3);			  // 오름차순으로 sort한다는걸 내림차순으로 착각해 시간날림 기초에 충실할 필요 있음
	return idx[2] + idx[1];
}

int main(void) {
	cin >> n;
	int cnt = 3;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	DP[0] = arr[0];
	DP[1] = arr[0] + arr[1];
	DP[2] = getmax(arr[0] , arr[1] , arr[2]);
	while (cnt < n) {
		DP[cnt] = max(DP[cnt - 3] + arr[cnt - 1], DP[cnt - 2]) + arr[cnt];
		DP[cnt] = max(DP[cnt], DP[cnt - 1]); // 현제의 자리에서 안마시는 케이스일때 전까지의 max와 비교 해야함
		cnt++;
	}
	cout << DP[n-1];
}
//https://www.acmicpc.net/problem/2156
//전날에 풀었던 계단 문제를 복습할겸풀었는데 조건이 조금 달라서 고민을했음
// 현제 자리에서 안마시고 끝낼 수 있는 케이스를 고려해야함