#include<iostream>

using namespace std;

int check[10];
int arr[10];
int tmp_arr[10];
int max_idx;
int N;

int max(int a, int b) { return a > b ? a : b; }

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

int cal() {
	int res = 0;
	for (int i = 0; i < N-1; i++)
		res += abs(tmp_arr[i] - tmp_arr[i + 1]);
	return res;
}

int dfs(int n) {
	if (n == N-1) 
		return cal();
	
	for (int i = 0; i < N; i++) {
		if (check[i]) continue;

		tmp_arr[n+1] = arr[i];
		check[i] = 1;
		dfs(n+1);
		check[i] = 0;
	}

	return 0;
}

void sol()
{
	int max_idx = 0;
	for (int i = 0; i < N; i++) {
		check[i] = 1;
		tmp_arr[0] = arr[i];
		max_idx=max(dfs(0),max_idx);
		check[i] = 0;
	}
	cout << max_idx;
}

int main(void)
{
	Input();
	sol();
}