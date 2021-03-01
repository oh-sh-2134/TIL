#include<iostream>
#define MAX 1001
using namespace std;

int DP[MAX];
int n;

int tile(int i) {
	if (i == 1) return 1;
	if (i == 2) return 3; // n-2에 존재하는 케이스는 2,2 하나와 2,1 1,2 각각 두개씩 채우는 총 세가지
						// return 하는 케이스에서는 마지막 2칸만 남았다고 생각해서 3개의 케이스
	if (DP[i] != 0) return DP[i];
	return DP[i] = (tile(i - 1) + 2*tile(i - 2))%10007; 
}								// 2곱하는 이유는2,2 로 채우는 방법과 1,2로 두개 채우는 방법 2,1로 채우면 
								// i == 1 케이스와 같아짐
								
int main(void) {
	cin >> n;
	cout << tile(n);
}
// https://www.acmicpc.net/problem/11727
// 타일링 문제 2