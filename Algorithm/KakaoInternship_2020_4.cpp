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
// roads_rows는 2차원 배열 roads의 행 길이, roads_cols는 2차원 배열 roads의 열 길이입니다.
// traps_len은 배열 traps의 길이입니다.
int solution(int n, int start, int end, vector<vector<int>> roads, size_t roads_rows, size_t roads_cols, vector<int> traps, size_t traps_len) {
	int answer = 0;
	for (auto road : roads)
	{
		int u = road[0];
		int v = road[1];
		int val = road[2];
		adj[u].push_back(make_pair(v,val));
		adjrev[v].push_back(make_pair(u, val));
	}
	for (int i = 0; i < n; i++)
		memset(dp[i], *dp[i] + 1024, 987654321);
	memset(trapidx, *trapidx + n, -1);
	for (int i = 0; i < traps.size(); trapidx) trapidx[traps[i]] = i;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
	q.push({ dp[start][0], start, 0 });
	while (!q.empty()) {
		int val, idx, state;
		tie(val, idx, state) = q.top();
		q.pop();
		if (idx == end) return val;
		if (dp[idx][state] != val) continue;
		for (auto p : adj[idx]) 
		{ 
			int nxt = p.first;
			int dist = p.second;
			int rev = 0;
			if (trapidx[idx] != -1 && bitmask(state, idx)) rev ^= 1; 
			if (trapidx[nxt] != -1 && bitmask(state, nxt)) rev ^= 1; 
			if (rev) continue; 
			int nxt_state = state;
			if (trapidx[nxt] != -1) nxt_state ^= (1 << trapidx[nxt]);
			if (dp[nxt][nxt_state] > dist + val) 
			{
				dp[nxt][nxt_state] = dist + val;
				q.push({ dp[nxt][nxt_state],nxt,nxt_state });
			}
		}

		for (auto p : adjrev[idx]) { 
			int nxt = p.first;
			int dist = p.second;
			int rev = 0;
			if (trapidx[idx] != -1 && bitmask(state, idx)) rev ^= 1;
			if (trapidx[nxt] != -1 && bitmask(state, nxt)) rev ^= 1;
			if (!rev) continue; 
			int nxt_state = state;
			if (trapidx[nxt] != -1) nxt_state ^= (1 << trapidx[nxt]);
			if (dp[nxt][nxt_state] > dist + val) {
				dp[nxt][nxt_state] = dist + val;
				q.push({ dp[nxt][nxt_state],nxt,nxt_state });
			}
		}
	}
	return -1; // unreachable
}

//https://github.com/encrypted-def/kakao-blind-recruitment/blob/master/2021-internship/Q4.cpp#L35
//공부 자료
