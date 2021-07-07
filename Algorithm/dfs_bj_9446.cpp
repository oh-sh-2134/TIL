#include<iostream>

#define MAX 100001
using namespace std;

int arr[MAX];
int T, n, cnt;

void dfs()
{

}

void solution()
{
	dfs();
	cout << cnt;
}

void Input()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		solution();
	}
}
//https://www.acmicpc.net/problem/9466
//dfs를 돌긴해야하는데 아이디어 안떠오름