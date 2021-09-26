#include <iostream>
using namespace std;

int arr[100];
int n, m;
void Input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int solution()
{
	int result = 0;
	int sum = 0;

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = arr[i] + arr[j] + arr[k];
				if (sum > result && sum <= m) result = sum;
			}
		}
	}
	return result;
}
int main(void)
{

	Input();
	int sol = solution();
	cout << sol;
	return 0;
}

//https://www.acmicpc.net/problem/2798
//브루트 포스 알고리즘의 기본 형태에 가까운 문제