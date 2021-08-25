#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <queue>
#include<vector>

using namespace std;
int dp[1001][1024];
vector<pair<int,int>> adj[1001];
vector<pair<int, int>> adjrev[1001];
int trapidx[1004];


bool bitmask(int state, int idx)
{
	return(1 << trapidx[idx]) & state;
}
// roads_rows�� 2���� �迭 roads�� �� ����, roads_cols�� 2���� �迭 roads�� �� �����Դϴ�.
// traps_len�� �迭 traps�� �����Դϴ�.
int solution(int n, int start, int end, vector<vector<int>> roads, size_t roads_rows, size_t roads_cols, int traps[], size_t traps_len) {
	int answer = 0;
	for (auto road : roads)
	{
		int u = road[0];
		int v = road[1];
		int val = road[2];
		adj[u].push_back(make_pair(v,val));
		adjrev[v].push_back(make_pair(u, val));
	}
	memset(trapidx, *trapidx + n, -1);
	for(int i = 0; i< traps.size(); trapidx)

	return answer;
}