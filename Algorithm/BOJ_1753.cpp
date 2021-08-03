#include<iostream>
#include<vector>
#include<queue>
#define MAX 20001
#define INF 987654321
#define endl "\n"
using namespace std;

int node[MAX];
vector<pair<int, int>> connect[MAX];
int V, E, K;

void init(int a)
{
	for (int i = 1; i <= a; i++)
	{
		node[i] = INF;
	}
}
void Input() {
	int u, v,w;
	cin >> V >> E >> K;
	init(V);
	while (E--)
	{
		cin >> u >> v >> w;
		connect[u].push_back(make_pair(v, w));
	}
}

void dijkstra(int a)
{
	node[a] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, a));
	while (!q.empty())
	{
		int dist = -1*q.top().first;
		int current = q.top().second;
		q.pop();

		if (node[current] < dist) continue;

		for (int i = 0; i < connect[current].size(); i++)
		{
			int next = connect[current][i].first;
			int next_dist = dist + connect[current][i].second;

			if (next_dist < node[next])
			{
				node[next] = next_dist;
				q.push(make_pair(-1 * next_dist, next ));
			}
		}
	}
}

int main(void) {
	Input();
	dijkstra(K);
	for (int i = 1; i <= V; i++)
	{
		if (node[i] == INF)
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << node[i] << endl;
		}
	}
}
//https://www.acmicpc.net/problem/1753
//다익스트라 기본 개념 문제
// priority_queue에 넣을때 (간선번호, 가중치)로 넣으면 시간 초과남 (가중치, 간선번호)로 넣어야 함