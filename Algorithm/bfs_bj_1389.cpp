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
//https://www.acmicpc.net/problem/1389
//BFS를 사용하여서 풀었지만 케빈베이컨 알고리즘을 이용하여 한번더 풀어볼 것.
