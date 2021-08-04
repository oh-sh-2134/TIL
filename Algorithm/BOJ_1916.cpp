#include<iostream>
#include<queue>
#include<vector>

#define MAX 1001
#define INF 987654321

using namespace std;

int N,M, s,d,v;

vector<pair<int,int>>connect[MAX];
int val[MAX];
int node[MAX];

void Init(int a){
	for(int i = 1; i<=a;i++)
	{
		node[i] = INF;
	}
}

void Input(){
	cin >> N >> M;
	while(M--)
	{
		cin >> s >> d >> v;
		connect[s].push_back(make_pair(d,v));
	}
	cin >> s >> d;
	Init(N);

}

void dijkstra(int start)
{
	node[start] = 0;
	priority_queue<pair<int,int>>q;
	q.push(make_pair(0,start));

	while(!q.empty())
	{
		int current_dist = -q.top().first;
		int current = q.top().second;
		q.pop();
		if(current_dist	> node[current]) continue;

		for(int i=0; i<connect[current].size() ; i++)
		{
			int next = connect[current][i].first;
			int next_dist = current_dist + connect[current][i].second;
			

			if(node[next] > next_dist)
			{
				node[next] = next_dist;
				q.push(make_pair(-next_dist, next));
			}
 		}
	}
}

int main(void)
{
	Input();
	dijkstra(s);
	cout << node[d];
}
//https://www.acmicpc.net/problem/1916
//Dijkstra 알고리즘 기초개념