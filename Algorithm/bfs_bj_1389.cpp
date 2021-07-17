#include<iostream>
#include<vector>
#include<queue>
#define MAX 101

using namespace std;

int n, m;
vector<vector<int>> node;
bool visited[MAX];
int dp[MAX];
int connect;

void MakeConnect(int a, int b) {
	node[a].push_back(b);
	node[b].push_back(a);
}
void Input() {
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		MakeConnect(a, b);
	}
}

void bfs(int n) {
	visited[n] = true;
	queue<int> q;
	q.push(n);
	int cnt = q.size();
	while (cnt--) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < node[current].size(); i++)
		{
			int next = node[current][i];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
				dp[next] = dp[current] + 1;
			}
		}
	}

	for (int i = 0; i < node[n].size(); i++)
	{
		connect += dp[node[n][i]];
	}
}

void solution() {
	for (int i = 1; i < n; i++)
	{
		memset(visited, visited[n], false);
		memset(dp, dp[n], false);
		bfs(i);
	}
}

void solution() 
{
	Input();
	solution();
}