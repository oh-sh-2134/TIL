#include<iostream>

using namespace std;

int n, m;
int arry[7];

void dfs(int a) {
	if (a == m) {
		for (int i = 0; i < m; i++) {
			cout << arry[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		arry[a] = i;
		dfs(a + 1);
	}
	
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	dfs(0);
}
//https://www.acmicpc.net/problem/15651
// 시간 초과가 계속 나는 바람에 많이 찾아봤는데
// endl은 버퍼를 비워야 하기때문에 endl 보다 "\n"이 훨씬 빠르다는 것을 배움