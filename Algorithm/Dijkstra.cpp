#include<iostream>
#include<vector>
#define INF 987654321
#define N 10
using namespace std;

vector<pair<int,int>> connect_info[N];
// <간선, 가중치>를 가지는 연결정보

void Dijkstra(int start)
{
	vector<int>node_dist(N, INF);
	//current 노드의 최단거리 그래프가 저장될 벡터 배열
	vector<bool>visited(N, false);
	//노드의 방문 여부를 저장할 벡터 배열


	node_dist[start] = 0;
	visited[start] = true;
	//start 노드에 대한 처리
	while (true)
	{
		int current;
		int closest_dist = INF;
		
		for (int i = 0; i < N; i++)
		{
			if (node_dist[i] < closest_dist && !visited[i])
			{
				current = i;
				closest_dist = node_dist[i];
			}
		}
		//방문하지 않은 노드중 최단거리 노드를 찾는다.

		if (closest_dist == INF) break;
		//연결되어 있는 노드를 모두 방문 했을경우 탈출

		visited[current] = true;
		for (int i = 0; i < connect_info[current].size(); i++)
			//current 노드와 연결되어 있는 노드를 모드방문
		{
			int next = connect_info[current][i].first;

			if (visited[next]) continue;
			
			int next_dist = connect_info[current][i].second;
			if (node_dist[next] > next_dist + node_dist[current])
				//기존에 가지고 있는 거리보다 가까울 경우 갱신
			{
				node_dist[next] = next_dist + node_dist[current];

			}
		}
	}
}


/*
우선순위 큐 사용
vector<pair<int, int>> connect_info[N];
// <간선, 가중치>를 가지는 연결정보

void Dijkstra(int start) {
	vector<int> node_dist(N, INF);
	node_dist[start] = 0;
	priority_queue<pair<int, int> > p_q;
	p_q.push(make_pair(0, start));

	while (!p_q.empty()) {
		int current_dist = -p_q.top().first;
		int current = p_q.top().second;
		p_q.pop();

		if (node_dist[current] < current_dist) continue;
		//현제 방문한 노드가 가지고있는 최소거리보다 큰 가중치를 가졌으면 확인하지 않음

		
		for (int i = 0; i < connect_info[current].size(); ++i) 
			// 해당 노드에서 인접한 정점들을 모두 확인
		{
			int next = connect_info[current][i].first;
			int next_dist = connect_info[current][i].second;
			// 더 짧은 경로를 발견하면, node_dist를 갱신하고 다음 확인대상에 추가하기위해 우선순위 큐에 넣음
			if (node_dist[next] > next_dist + current_dist) {
				node_dist[next] = next_dist + current_dist;
				p_q.push(make_pair(-node_dist[next], next));
			}
		}
	}
}
*/