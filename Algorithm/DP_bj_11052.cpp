#include<iostream>
#define MAX 1002


using namespace std;

int arr[MAX];
int DP[MAX];
int n;
int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			DP[i] = max(DP[i - j] + arr[j], DP[i]);
		}
	}
	cout << DP[n];
}
//https://www.acmicpc.net/problem/11052
//처음에 생각 했던 방식은 결국 지금 카드팩을 선택하는 최고의 케이스를 뽑지 못하고 그 케이스를 체크하기 위해서는 
//결국 지금 카트팩의 케이스에서 모든케이스를 체크를 해야한다고 판단하고 위의 코드로 완전히 엎어버림
//생각하는 능력이 많이 늘고 있다고 생각했는데 역시 난 천재는 아닌가봄 노력하자 
/*int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		DP[i] = max(DP[i], DP[i - 1] + arr[1]);
		if (arr[i] > DP[i]) {
			int a = n / i;
			for (int j = 1; j <= a; j++) {
				//DP[j*i] = arr[i] * j;
				DP[j*i] = max(DP[j*i] , arr[i] * j);
				DP[n] = max(DP[n], DP[j*i] + DP[n - j * i]);
			}
		}
	}
	cout << DP[n];
}*/
/* 반례 도움 주신분 yj10516
6

1 5 6 1 1 1

Ans: 15
반례도움 받아서 39번라인 수정 했지만 아직 막힘

12
1 1 6 8 11 1 1 1 1 1 1 1
정답 : 25
추가 반례

7번째에서 3 4를 조합하여 14가 나와야하는데 5번째에서 11 때문에 13으로 유지가 됨
해당 케이스를 수정하기 위해서는 방문할때마다 해당 카드팩을 선택할때 모든케이스를 고려하는 조건을 넣어야하는데
그렇게 되면 에초에 처음부터 모든케이스를 고려해나가는 점화식을 세우는게 훨씬 깔끔하고 확실하다고 판단되어서
코드를 갈아엎음 
*/