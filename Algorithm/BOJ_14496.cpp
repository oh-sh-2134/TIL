#include<iostream>
#define MAX 1001
#define INF 987654321
using namespace std;

int node[MAX][MAX];
bool visted[MAX];
int n, m;
int a, b;

void Input() {
	
	cin >> a >> b >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		node[x][y] = 1;
		node[y][x] = 1;
	}
}


void MakeTable() {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) node[i][j] = 0;
			else node[i][j] = INF;
		}
	}
}

void dihkstra(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			
		}
	}

}

//https://www.acmicpc.net/problem/14496
//다익스트라 알고리즘 공부 필요함