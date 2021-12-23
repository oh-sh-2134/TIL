#include<iostream>
#include <queue>
#include<stack>
#include<cstring>
using namespace std;

int arr[101][101];
bool visited[101][101];
int N, L, R;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

stack<pair<int, int>> stk;
queue<pair<int, int>> graph;

// 입력을 받는 역활
void Input() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}

//국경 공유시 인원 배분하는 역활
bool ChangeArray(int result) {

	//국경 공유가 없을때
	if (result == -1 ) return false;

	while (!stk.empty()) {
		int y = stk.top().first;
		int x = stk.top().second;
		stk.pop();
		arr[y][x] = result;
	}
	return true;
}

//인원 배분이 필요한 나라를 찾는 역활
int bfs(int a, int b) {
	graph.push({ a, b });

	int country_cnt = 0;
	int members = 0;

	while (!graph.empty()) {
		int y = graph.front().first;
		int x = graph.front().second;
		graph.pop();
		if (visited[y][x]) continue;
		visited[y][x] = true;
		
		stk.push({ y,x });
		country_cnt++;
		members += arr[y][x];

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
			if (abs(arr[y][x] - arr[ny][nx]) >= L && abs(arr[y][x] - arr[ny][nx]) <= R) {
				if (visited[ny][nx]) continue;
				graph.push({ ny,nx });
					
			}
				
		}
	}

	// 국경을 공유할 나라가 없을때
	if (country_cnt <= 1) {
		if(!stk.empty()) stk.pop();
		return -1;
	}

	//국경을 공유할 나라의 인원 배분 값
	return members / country_cnt;
}

//함수 조합 역활
int solution() {
	int move_cnt = 0;
	bool flag;
	do{
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 한번이라도 국경을 공유했을시 flag on
				if (ChangeArray(bfs(i, j)))
					flag = true;
			}
		}
		if(flag)
			move_cnt++;
		memset(visited, false, sizeof(visited));
	} while (flag);

	return move_cnt;
}

int main(void) {
	
	Input();
	int sol = solution();
	cout << sol;
}

//https://www.acmicpc.net/problem/16234
//4퍼에서 입구컷 ㄷㄷ;
//조건에 만족하는 두 나라만 국경선을 공유해야함 -> 재구현
/*
4 1 9
96 93 74 30
60 90 65 96
5 27 17 98
10 41 46 20
correct: 1
*/
