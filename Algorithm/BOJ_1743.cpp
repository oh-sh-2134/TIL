#include<iostream>

#define MAX 101

using namespace std;

int arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m,c;

int Max(int a, int b)
{
	return a>b?a:b;
}
void Input(){
	cin>> n >> m >> c;
	while(c--)
	{
		int a,b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
}

int dfs(int y, int x)
{
	int cnt = arr[y][x];
	visited[y][x] = true;
	for(int i = 0 ; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(ny < 1 || ny > n || nx < 1 || nx > m) continue;

		if(arr[ny][nx] == 1 && !visited[ny][nx])
			cnt += dfs(ny,nx);
	}
	return cnt;
}

int main(){
	Input();
	int max=0;
	for(int i = 1 ; i <= n; i++)
	{
		for(int j = 1 ; j <= m; j++)
		{
			if(arr[i][j] == 1 && !visited[i][j])
			{
				max = Max(max, dfs(i,j));
			}
		}
	}
	cout << max;
}
//https://www.acmicpc.net/problem/1743
//bfs로 풀었음 / 난이도★
