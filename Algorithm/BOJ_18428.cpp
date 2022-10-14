#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> arr;
vector<pair<int, int>> teacher;
bool canAvoid = false;
void input() {
	cin >> N;
	arr.resize(N, vector<char>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'T')
				teacher.push_back({ i,j });
		}
	}
}

void avoidMonitor() {
	for (int i = 0; i < teacher.size(); i++) {

		bool flag = true;
		auto current = teacher[i];
		//위로
		while (flag) {
			
		}

		//아래
		while (flag) {

		}

		//오른쪽
		while (flag) {

		}

		//왼쪽
		while (flag) {

		}
	}
}

void dfs(int cnt) {
	if (cnt == 3) {
		avoidMonitor();
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != 'X') continue;
			arr[i][j] = 'O';
			dfs(cnt + 1);
			if (canAvoid) return;
			arr[i][j] = 'X';
		}
	}
}

void solution() {
	dfs(1);
	if (canAvoid) cout << "YES";
	else cout << "NO";
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/18428