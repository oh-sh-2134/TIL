#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10000001
using namespace std;
vector<vector<pair<int, int>>> adj;
vector<int>intensitys;
vector<int>nodeInfo;

enum { GATE = 1, SUMMIT = 2 };

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;
	priority_queue<pair<int, int>> pq;
	adj.resize(n + 1, vector<pair<int, int>>());
	intensitys.resize(n + 1, MAX);
	nodeInfo.resize(n + 1, 0);
	//nodeInfo에 GATE 표시, intensitys 초기화, q에 push
	for (auto& gate : gates) {
		nodeInfo[gate] = GATE;
		intensitys[gate] = 0;
		pq.push({ gate,0 });
	}
	//nodeInfo에 SUMMIT 표시
	for (auto& summit : summits) {
		nodeInfo[summit] = SUMMIT;
	}

	for (auto & path : paths) {
		//시작이 GATE이거나 도착이 SUMMIT일때는 반대로 가는 간선 정보를 입력하지 않아도 됨
		if (nodeInfo[path[0]] == GATE || nodeInfo[path[1]] == SUMMIT) {
			adj[path[0]].push_back({ path[1],path[2] });
		}
		//시작이 SUMMIT일때는 도착이 GATE일때는 반대로 가는 간선 정보만 입력해야 함
		else if (nodeInfo[path[0]] == SUMMIT || nodeInfo[path[1]] == GATE) {
			adj[path[1]].push_back({ path[0],path[2] });
		}
		//일반 노드끼리의 간선정보 입력
		else {
			adj[path[0]].push_back({ path[1],path[2] });
			adj[path[1]].push_back({ path[0],path[2] });
		}
	}
	//다익스트라 변형
	while (!pq.empty()) {
		int currentNode = pq.top().first;
		int currentIntensity = pq.top().second;
		pq.pop();

		if (nodeInfo[currentNode] == SUMMIT) continue;

		//현재의 currentIntensity보다 intensitys[currentNode]가 크다면 
		//현재 노드보다 더 작은 intensitys를 가질 수 없기때문에 스킵
		if (intensitys[currentNode] > currentIntensity) continue;

		for (auto& iter : adj[currentNode]) {
			int nextNode = iter.first;
			int nextIntensity = iter.second;

			//intensitys[nextNode]를 갱신 할 수 없다면 패스
			if (intensitys[nextNode] <= max(currentIntensity, nextIntensity)) continue;

			//intensitys[nextNode] 업데이트, push in q
			intensitys[nextNode] = max(currentIntensity, nextIntensity);
			pq.push({ nextNode,intensitys[nextNode] });

		}
	}

	//summits을 정렬하여 작은 숫자를 가진 summit가 먼저 처리 되야 함
	sort(summits.begin(), summits.end());
	//최소 intensitys를 찾기 위해 최댓값으로 초기화
	answer = { 0, MAX };
	//intensitys의 최소를 찾자
	for (auto& summit : summits) {
		if (intensitys[summit] >= answer[1]) continue;
		answer[0] = summit;
		answer[1] = intensitys[summit];

	}


	return answer;
}

int main(void) {
	vector<vector<int>> v1 = { {1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1} };
	vector<int> g = { 1, 3 };
	vector<int> s = { 5 };
	solution(6, v1, g, s);
}
//https://school.programmers.co.kr/learn/courses/30/lessons/118669