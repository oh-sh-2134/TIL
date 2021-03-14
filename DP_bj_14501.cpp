#include<iostream>
#define MAX 16

using namespace std;
int tc,top;
int DP[MAX];
int arr[MAX][2];
int max(int a, int b) {
	return a > b ? a : b;
}
int work() {
	for (int i = 0; i < tc; i++) {
		if (tc < arr[i][0] + i) continue;
		if (DP[i] <top) {
			int f = i;
			int idx=0;
			while (f>0) { // 최댓값을 찾으로 첫번째 원소까지 가야함 
				if (DP[f]) // 값이 있으면
					idx = max(idx, DP[f]); // 크기비교
				f--;
			}
			DP[i] = idx;
		}
		DP[i + arr[i][0]] = max(DP[i] + arr[i][1], DP[i + arr[i][0]]);
		//이동했을때의 크기가 가장 커야함 
		if (top < DP[i + arr[i][0]])
			top = DP[i + arr[i][0]];
	}
	return top;
}
int main(void) {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	cout << work();
	
}
//https://www.acmicpc.net/problem/14501
//한 사이클에 최대 합을 찾는 방법을 고민을 했고 찾아냈음
//처음에는 DP[i]번째에 값이 없을때(0)만 뒤로가서 최댓값을 가지고 왔는데
//아래의 반래를 보고는 번뜩 생각이 나서 고쳤다.. 현제 DP[i]가 최댓값이 되지만은 않는다는 것을
/*7
2 10
5 1
5 1
5 1
5 1
5 1
1 10
오답 11
정답 20
*/