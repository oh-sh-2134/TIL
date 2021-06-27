#include<iostream>
#define MAX 250
using namespace std;

int dx[8] = { 0,0,1,-1,1,-1,-1,1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int m, n,cnt;
int arr[MAX][MAX];

void Input()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void dfs(int a, int b)
{
	if (arr[a][b] == 1)
	{
		arr[a][b] = 2;
		for (int i = 0; i < 8; i++)
		{
			int y = a + dy[i];
			int x = b + dx[i];
			if (x < 0 && y < 0 && x >= m && y >= n) continue;
			dfs(y, x);
		}
	}

}

void solution()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;

}

int main(void)
{
	Input();
	solution();
}

//https://www.acmicpc.net/problem/14716
