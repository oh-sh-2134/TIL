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

//���� �湮�� ����� ���¸� S�� ��Ÿ��
void dfs(int s) {

	//���� ��� ���´� ����ߴ���
	if (state[s]) return;
	state[s] = 1;

	int num = 0, worfCnt = 0;
	for (int i = 0; i < worfState.size(); i++) {
		//�湮�� ����� ī���ð� ���� �� ����
		if (s&(1 << i)) {
			num++;
			worfCnt += worfState[i];
		}
	}

	//�� �湮�� ����� ���� ���� ������ �� x 2�� ������ ���ų� ������ �Ұ����� ���̽�
	if (worfCnt * 2 >= num) return;

	sol = max(sol, num - worfCnt);

	//���� ��� Ž��
	for (int i = 0; i < worfState.size(); i++) {
		//�湮���� ���� ��忡�� �ش� ����� �ڽĳ��� ���� ���� �Ұ�����
		if (!(s&(1 << i))) continue;

		//�湮�ߴ� ����� �ڽ� ��尡 �ִٸ� state�����Ͽ� �ش� ���̽� Ž��
		for (auto iter : tree[i]) {
			dfs(s | (1 << iter));
		}
	}
}
//��Ʈ ����ŷ ����Ҳ� �湮�� ��带 1, �湮���� ���� ��� 0ó��
int solution(vector<int> info, vector<vector<int>> edges) {
	//���������� ����ȭ
	for (auto iter : info)
		worfState.push_back(iter);

	int num = 0;
	//Ʈ������ ����ȭ
	for (auto iter : edges)
		tree[iter[0]].push_back(iter[1]);

	//0��° ��带 �湮�� ���´� ��Ʈ�� 00...01��
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