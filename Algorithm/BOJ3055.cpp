#include<iostream>
#include<queue>
#define MAX 51
using namespace std;

char arr[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>>s_q;
queue<pair<int, int>>water_q;

void Input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') s_q.push({ i,j });
			else if (arr[i][j] == '*') water_q.push({ i,j });
		}
	}
}

void solution() {
	int water_qsize = water_q.size();
	int s_qsize = s_q.size();
	int cnt = 0;
	while (!s_q.empty()) {
		water_qsize = water_q.size();
		s_qsize = s_q.size();
		while (water_qsize--) {
			int water_y = water_q.front().first;
			int water_x = water_q.front().second;
			water_q.pop();
			for (int i = 0; i < 4; i++) {
				int move_y = water_y + dy[i];
				int move_x = water_x + dx[i];
				if (move_y < 0 || move_y >= n || move_x < 0 || move_x >= m) continue;
				if (arr[move_y][move_x] == '.') {
					arr[move_y][move_x] = '*';
					water_q.push({ move_y ,move_x });
				}
			}
		}
		cnt++;
		while (s_qsize--) {
			int s_y = s_q.front().first;
			int s_x = s_q.front().second;
			s_q.pop();
			visited[s_y][s_x] = true;
			for (int i = 0; i < 4; i++) {
				int move_y = s_y + dy[i];
				int move_x = s_x + dx[i];
				if (move_y < 0 || move_y >= n || move_x < 0 || move_x >= m) continue;
				if (arr[move_y][move_x] == 'D') {
					cout << cnt;
					return;
				}
				if (arr[move_y][move_x] == '.' || visited[move_y][move_x]) 
					s_q.push({ move_y ,move_x });
				
			}
		}
		

	}
	cout << "KAKTUS";

}

int main(void) {
	Input();
	solution();
}
//https://www.acmicpc.net/problem/3055