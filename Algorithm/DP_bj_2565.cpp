#include<iostream>
#include<queue>
#define MAX 500

using namespace std;


int A[MAX], B[MAX];
int cnt;
int min(int a, int b){
	return a > b ? b : a;
}

int sol() {
	queue<int> q;
	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			
			if (A[i] > A[j] && B[i] > B[j]) continue;
			if (A[i] < A[j] && B[i] < B[j]) continue;
			q.push[j];

		}
	}
}
int main(void) {
	
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> A[i] >> B[i];
	}


}
//https://www.acmicpc.net/problem/2565
//0517 전깃줄을 A와 B로 나누고 차례로 비교해나가며 곂치는걸 지우는 방식을 생각