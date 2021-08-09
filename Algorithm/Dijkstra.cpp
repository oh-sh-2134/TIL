#include<iostream>
#include<vector>
#define INF 987654321
#define N 10
using namespace std;

vector<pair<int,int>> connect_info[N];
// <����, ����ġ>�� ������ ��������

void Dijkstra(int start)
{
	vector<int>node_dist(N, INF);
	//current ����� �ִܰŸ� �׷����� ����� ���� �迭
	vector<bool>visited(N, false);
	//����� �湮 ���θ� ������ ���� �迭


	node_dist[start] = 0;
	visited[start] = true;
	//start ��忡 ���� ó��
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
		//�湮���� ���� ����� �ִܰŸ� ��带 ã�´�.

		if (closest_dist == INF) break;
		//����Ǿ� �ִ� ��带 ��� �湮 ������� Ż��

		visited[current] = true;
		for (int i = 0; i < connect_info[current].size(); i++)
			//current ���� ����Ǿ� �ִ� ��带 ���湮
		{
			int next = connect_info[current][i].first;

			if (visited[next]) continue;
			
			int next_dist = connect_info[current][i].second;
			if (node_dist[next] > next_dist + node_dist[current])
				//������ ������ �ִ� �Ÿ����� ����� ��� ����
			{
				node_dist[next] = next_dist + node_dist[current];

			}
		}
	}
}


/*
�켱���� ť ���
vector<pair<int, int>> connect_info[N];
// <����, ����ġ>�� ������ ��������

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
		//���� �湮�� ��尡 �������ִ� �ּҰŸ����� ū ����ġ�� �������� Ȯ������ ����

		
		for (int i = 0; i < connect_info[current].size(); ++i) 
			// �ش� ��忡�� ������ �������� ��� Ȯ��
		{
			int next = connect_info[current][i].first;
			int next_dist = connect_info[current][i].second;
			// �� ª�� ��θ� �߰��ϸ�, node_dist�� �����ϰ� ���� Ȯ�δ�� �߰��ϱ����� �켱���� ť�� ����
			if (node_dist[next] > next_dist + current_dist) {
				node_dist[next] = next_dist + current_dist;
				p_q.push(make_pair(-node_dist[next], next));
			}
		}
	}
}
*/