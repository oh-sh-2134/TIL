#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#define MAX 101

using namespace std;

int n, m;

bool node[MAX][MAX];
int visited[MAX];
int temp[MAX];



void Input() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		node[a][b] = true;
		node[b][a] = true;
	}
}

void bfs(int num) {
	visited[num] = 0;
	queue<int> q;
	q.push(num);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == -1 && node[current][i])
			{
				visited[i] = visited[current] + 1;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] > 0)
		{
			temp[num] += visited[i];
		}
	}
}

void solution() {
	for (int i = 1; i <= n; i++)
	{
		memset(visited, -1, sizeof(visited));
		bfs(i);
	}
	int min = temp[1];
	int sol = 1;
	for (int i = 2; i <= n; i++) {
		if (min > temp[i]) {
			min = temp[i];
			sol = i;
		}
	}
	cout << sol;
}

int main(void) 
{
	Input();
	solution();
}
/*
#include<iostream>
#define MAX 101
#define INF 987654321
using namespace std;

int node[MAX][MAX];
int visited[MAX];
int temp[MAX];

int n, m;


void Floyd_Warshall()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				if (node[i][j] > node[i][k] + node[k][j]) {
					node[i][j] = node[i][k] + node[k][j];
				}
				
			}
		}
	}


}

void MakeTable() 
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) 
				node[i][j] = 0;
			else 
				node[i][j] = INF;
		}
	}
}

void Input() {
	cin >> n >> m;
	MakeTable();
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		node[a][b] = 1;
		node[b][a] = 1;
	}
}

void solution() {
	int sol,min = INF;
	Floyd_Warshall();
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			sum += node[i][j];
		}
		cout << temp[i] << "\n";
		if (min > sum)
		{
			min = sum;
			sol = i;
		}
	}
	cout << sol;
}

int main(void) 
{
	Input();
	solution();
}
*/
//https://www.acmicpc.net/problem/1389
//BFS를 사용하여서 풀었지만 플로이드 와샬 알고리즘을 이용하여 한번더 풀어볼 것.
//플로이드 와샬 - 모든노드가 모든 노드를 한번씩 방문하는 최단거리를 구하는 공식
//A -> B로 갈때 A-> C , C-> B 로가는게 더 짧을 가능성을 찾는 알고리즘
