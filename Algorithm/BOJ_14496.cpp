#include<iostream>
#define MAX 1001
#define INF 987654321
using namespace std;

int node[MAX][MAX];
bool visited[MAX];
int dist[MAX];
int n, m;
int a, b;

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

void Input() {
	
	cin >> a >> b >> n >> m;
	int x, y;
	MakeTable();
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		node[x][y] = 1;
		node[y][x] = 1;
	}
}


int GetSmallDist(){
	int nodenum = 0;
	int min = INF;
	for(int i=1;i<=n;i++){
		if(min> dist[i] && !visited[i])
		{
			min = dist[i];
			nodenum = i;
		}
	}
	return nodenum;
}

int dihkstra(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		dist[i] = node[n][i];
	}
	visited[n] = true;
	for(int i=1; i<=n-2; i++)
	{
		int current = GetSmallDist();
		visited[current] = true;
		for(int j = 1;j<=n ; j++)
		{
			if(!visited[j])
			{
				if(dist[j] > node[current][j] + dist[current])
					dist[j] = node[current][j] + dist[current];
			}
		}
	}
	return node[a][b];
}

int main(void){
	int sol;
	Input();
	sol = dihkstra(a);
	cout << sol;
}

//https://www.acmicpc.net/problem/14496
//다익스트라 알고리즘 공부 필요함
//다익스트라 알고리즘으로 1
