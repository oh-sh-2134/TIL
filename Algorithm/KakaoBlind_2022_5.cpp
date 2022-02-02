#include<iostream>
#include <string>
#include <vector>
#define MAX 17
using namespace std;
vector<int> tree[MAX];
vector<int> worfState;
int state[1 << MAX];
int sol = 1;

int max(int a, int b) { return a > b ? a : b; }

//현재 방문한 노드의 상태를 S로 나타냄
void dfs(int s) {

	//현재 노드 상태는 계산했는지
	if (state[s]) return;
	state[s] = 1;

	int num = 0, worfCnt = 0;
	for (int i = 0; i < worfState.size(); i++) {
		//방문한 노드의 카운팅과 늑대 수 관리
		if (s&(1 << i)) {
			num++;
			worfCnt += worfState[i];
		}
	}

	//총 방문한 노드의 수가 현재 늑대의 수 x 2를 했을때 같거나 작으면 불가능한 케이스
	if (worfCnt * 2 >= num) return;

	sol = max(sol, num - worfCnt);

	//다음 노드 탐색
	for (int i = 0; i < worfState.size(); i++) {
		//방문하지 않은 노드에서 해당 노드의 자식노드로 가는 것은 불가능함
		if (!(s&(1 << i))) continue;

		//방문했던 노드중 자식 노드가 있다면 state변경하여 해당 케이스 탐색
		for (auto iter : tree[i]) {
			dfs(s | (1 << iter));
		}
	}
}
//비트 마스킹 사용할꺼 방문한 노드를 1, 방문하지 않은 노드 0처리
int solution(vector<int> info, vector<vector<int>> edges) {
	//늑대정보를 전역화
	for (auto iter : info)
		worfState.push_back(iter);

	int num = 0;
	//트리정보 전역화
	for (auto iter : edges)
		tree[iter[0]].push_back(iter[1]);

	//0번째 노드를 방문한 상태는 비트로 00...01임
	dfs(1);

	int answer = sol;
	return answer;
}

int solution(vector<int> info, vector<vector<int>> edges) {

	for (auto iter : info)
		worfState.push_back(iter);

	for (auto iter : edges)
		tree[iter[0]].push_back(iter[1]);

	dfs(1);

	int answer = sol;
	return answer;
}

int main(void) {
	vector<int> info = { 0,0,1,1,1,0,1,0,1,0,1,1 };
	vector<vector<int>> edges = { {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9} };
	cout << solution(info, edges);
}
//https://programmers.co.kr/learn/courses/30/lessons/92343