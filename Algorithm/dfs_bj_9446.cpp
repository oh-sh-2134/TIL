#include<iostream>

#define MAX 100001
using namespace std;

int arr[MAX];
bool visited[MAX];
bool done[MAX];
int T, n, cnt;

void dfs(int Current)
{
	visited[Current] = true;
	int Next = arr[Current];
	if(!visited[Next])
		dfs(arr[Next]);
	else if(!done[Current])
		for(int i = Next; i != Current; i = arr[Next])
			cnt++;
	cnt++;

	done[Current] = true;
}

void solution()
{
	for(int i = 1; i<=n; i++)
	{
		if(!visited[i])
			dfs(1);
	}
	cout << n - cnt;
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
			visited[i] = false;
			done[i] = false;
		}
		solution();
	}
}

int main(void){
	Input();
}
//https://www.acmicpc.net/problem/9466
//dfs를 돌긴해야하는데 아이디어 안떠오름
