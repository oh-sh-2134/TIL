#include <iostream>
#include <string>
#include <vector>
using namespace std;

int r, c;
int cnt;
// y�� �밢�� ������ ���� Ž���ϰ� �ϴ°� ����Ʈ
//���� ���� �湮�� ��쿡 �Ʒ��� ���� �湮�Ҷ� �� ū ���������� ������ ���ð�츦 ���߸�
int my[3] = { -1,0,1 };
int mx[3] = { 1,1,1 };
vector<vector<char>> graph;

void input() {
	cin >> r >> c;
	graph.resize(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> graph[i][j];
		}
	}
}

bool dfs(int y, int x) {
	if (x == c - 1) {
		cnt++;
		return true;
	}

	graph[y][x] = 'x';
	for (int i = 0; i < 3; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (ny >= r || ny<0 || nx>=c || nx < 0 ) continue;
		if (graph[ny][nx] == 'x') continue;
		//Ž���� �� �̾�� üũ
		if (dfs(ny,nx))
			return true;
	}
	return false;

}
void solution() {
	for (int i = 0; i < r; i++) {
		dfs(i, 0);
	}
	cout << cnt;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/3109