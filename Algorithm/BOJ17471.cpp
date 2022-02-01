#include<iostream>
#include<queue>
#include<vector>

#define MAX 10

using namespace std;

int n;
vector<int> adj[MAX];
int pepleNum[MAX];
int state[1 << 10];
int visited[MAX];

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pepleNum[i];
	}
	for(int i =0 ;i < n ; i++){
		int a, b;
		cin >> a;
		while (a--) {
			cin >> b;
			adj[i].push_back(b-1);
		}
	}
}

// ���� ������ ����Ǿ� �ִ��� Ȯ���ϴ� Ž��
void BFS(int a, int s) {
	queue<int> q;
	q.push(a);

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		visited[current] = 3;
		for (int i = 0; i < adj[current].size(); i++) {
			int next = adj[current][i];
			if (visited[next] == s) {
				visited[next] = 3;
				q.push(next);
			}
		}
	}
}

void reset() {
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}
}

int min(int a, int b) {
	return a > b ? b : a;
}

int abs(int a) {
	return a > 0 ? a : (-1)*a;
}

bool checkDiv() {
	for (int i = 0; i < n; i++) {
		if (visited[i] != 3)
			return false;
	}
	return true;
}
//��Ʈ ����ŷ ��� 0�� 1�� �������� ���������ٰ� ����
void solution() {
	int area1, area2;
	int sol = 987654321;
	for (int s = 0; s < (1 << n); s++) {
		//�ʱ�ȭ �ؾ��ϴ� �� : ������ �ο����� ��, visited ����
		reset();
		area1 = 0;
		area2 = 0;

		for (int i = 0; i < n; i++) {
			//1�����϶� �ο��� ���ľ��� + BFS�� ���� visited ����
			if (s&(1 << i)) {
				area1 += pepleNum[i];
				visited[i] = 1;
			}
			else {
				area2 += pepleNum[i];
				visited[i] = 2;
			}
		}
		//BFS�� 2������ ��� ���� ���� �Ǿ� �ִ��� Ȯ��
		bool flag1 = true;
		bool flag2 = true;
		for (int i = 0; i < n; i++) {

			if (visited[i] == 1 && flag1) {
				BFS(i, 1);
				flag1 = false;
			}
			if (visited[i] == 2 && flag2) {
				BFS(i, 2);
				flag2 = false;
			}
		}
		
		
		// ������ ���� ������ �н�
		if (!checkDiv()) continue;

		int diff = abs(area1 - area2);

		if (sol > diff)
			sol = diff;
	}
	if (sol == 987654321)
		sol = -1;
	cout << sol;
}

int main(void) {
	Input();
	solution();
}
//https://www.acmicpc.net/problem/17471