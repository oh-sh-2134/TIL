#include<iostream>
#include <queue>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;


vector<pair<int, int>> adj[1001]; //정방향에 대한 정보
vector<pair<int, int>> adjrev[1001]; // 역방향에 대한 정보
int dp[1001][1024]; // 실제 거리를 담고 있는 정보 앞의 1001은 최대 노드를 나타내고 뒤에 1024는 나타날 수 있는 최대상태를 말함
int trapidx[1001]; //트랩노드의 정보

//state체크 - 트랩 활성화 상태를 비트로 나타내고 있음
bool bitmask(int state, int trap)
{
	return state & (1 << trap);
}
// roads_rows는 2차원 배열 roads의 행 길이, roads_cols는 2차원 배열 roads의 열 길이입니다.
// traps_len은 배열 traps의 길이입니다.
int solution(int n, int start, int end, vector<vector<int>> roads, size_t roads_rows, size_t roads_cols, vector<int> traps, size_t traps_len) {
	int answer = 0;
	for (auto road : roads)
	{
		adj[road[0]].push_back({ road[1],road[2] });
		adjrev[road[1]].push_back({ road[0],road[2] });
	}
	fill(trapidx, trapidx + n+1, -1);
	for (int i = 0; i < traps_len; i++) trapidx[traps[i]] = traps[i];
	for (int i = 0; i < roads_rows; i++) fill(dp[i], dp[i] + 1024, 987654321);
	//다익스트라 알고리즘 사용을 위해 우선큐 사용, < 현제까지의 거리 최소값, 현제노드번호, 트랩 활성화 정보 >
	priority_queue < tuple<int, int, int>,vector<tuple<int,int,int>> ,greater<tuple<int, int, int>>>q;
	dp[start][0] = 0;
	q.push({ dp[start][0], start, 0 });
	while (!q.empty())
	{
		int current_dist, current, state;
		tie(current_dist, current, state) = q.top();
		q.pop();
		if (current == end) return current_dist;
		if (dp[current][state] != current_dist) continue;
		for (auto node : adj[current])
		{
			int next = node.first;
			int next_dist = node.second;
			//현제노드와 다음 노드의 트랩 엑티브 상태를 파악하여 정방향인지 판단해야 함
			int rev = 0;
			if (trapidx[current] != -1 && bitmask(state,trapidx[current])) rev ^= 1; 
			if (trapidx[next] != -1 && bitmask(state, trapidx[next])) rev ^= 1;
			if (rev) continue;
			int next_state = state;
			if (trapidx[next] != -1)
				next_state ^= (1 << trapidx[next]);
			if (dp[next][state] > current_dist + next_dist)
			{
				dp[next][state] = current_dist + next_dist;
				q.push({ dp[next][state], next, next_state });
			}
		}

		for (auto node : adjrev[current])
		{
			int next = node.first;
			int next_dist = node.second;
			int rev = 0;
			//현제노드와 다음 노드의 트랩 엑티브 상태를 파악하여 역방향인지 판단해야 함
			if (trapidx[current] != -1 && bitmask(state, trapidx[current])) rev ^= 1;
			if (trapidx[next] != -1 && bitmask(state, trapidx[next])) rev ^= 1;
			if (!rev) continue;
			int next_state = state;
			if (trapidx[next] != -1) 
				next_state ^= (1 << trapidx[next]);
			if (dp[next][next_state] > current_dist + next_dist) 
			{
				dp[next][next_state] = current_dist + next_dist;
				q.push({ dp[next][next_state],next,next_state });
			}
		}

	}
	//목표까지 도달하지 못하면 retrun -1이지만 문제에서는 항상 탈출할 수 있는 케이스만 주어짐
	return -1; 
}

//https://github.com/encrypted-def/kakao-blind-recruitment/blob/master/2021-internship/Q4.cpp#L35
//코드 이해 -> 클론 코딩 -> 참고없이 혼자  
