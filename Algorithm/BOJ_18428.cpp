#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> arr;
vector<pair<int, int>> teacher;
bool canAvoid = false;

int mx[4] = { 0,0,1,-1 };
int my[4] = { 1,-1,0,0 };

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

//회피할 수 있는지 확인
bool avoidMonitor() {
	for (int i = 0; i < teacher.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int y = teacher[i].first;
			int x = teacher[i].second;
			while (true) {
				y += my[j];
				x += mx[j];
				//범위를 벗어나면 안됨
				if (y < 0 || y >= N || x < 0 || x >= N) break;
				//X이면 다음 공간을 확인 해야함
				if (arr[y][x] == 'X') continue;
				//S가 보이면 실패
				if (arr[y][x] == 'S') return false;
				//T와 O의 케이스
				break;
			}
		}
	}
	return true;
		
}

void dfs(int cnt) {
	//피할 수 있는 경우가 있다면 더 이상 탐색하지 않음
	if (canAvoid) return;
	//3개를 모두 설치했을때 확인
	if (cnt == 3) {
		canAvoid = avoidMonitor();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != 'X') continue;
			arr[i][j] = 'O';
			dfs(cnt + 1);
			arr[i][j] = 'X';
			if (canAvoid) return;
		}
	}
}

void solution() {
	//완전 탐색으로 풀이
	dfs(0);
	if (canAvoid) cout << "YES";
	else cout << "NO";
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/18428
