#include<iostream>
#include<bitset>
#define MAX 51
#define INF 987654321
using namespace std;


bitset<10> bit;
int dist[MAX][MAX];
int map[MAX][MAX];

int n, s;
int minIdx = INF;
int min(int a, int b) { return a > b ? b : a; }

void input() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
}


void dfs(int current, int currDist) {

	if (bit.count() == n)
		minIdx = min(currDist, minIdx);
	

	//�ּڰ����� ũ�ٸ�
	if (currDist > minIdx) return;

	//�༺ �湮
	for (int i = 0; i < n; i++) {
		//���� �湮�� �༺�̸�
		if (bit[i]) continue;
		bit[i] = 1;
		dfs(i, currDist + map[current][i]);
		bit[i] = 0;
	}
}

void solution() {

	//�÷��̵� �ͼ�
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (map[i][j] + map[j][k] < map[i][k])
					map[i][k] = map[i][j] + map[j][k];
			
		
	bit[s] = 1;
	dfs(s,0);
	cout << minIdx;
}
int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/17182
