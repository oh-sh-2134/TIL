#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX 101

int field[MAX][MAX];
bool visited[MAX][MAX];
int temp[MAX];
int Maxh;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n;

bool exection() { //빌딩의 높이가 모두 같을 경우를 위한 예외처리 함수
	int e = field[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (e != field[i][j]) return true;
		}
	}
	return false;
}
void set(int p) {// 물의 높이를 인자로 받아서 침수 된 빌딩은 방문처리하게 함
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] <= p) {
				visited [i][j] = true;
				
			}
			else visited[i][j] = false;
		}
	}
}

int dfs() { // stack으로 dfs문제푸는 연습
	int cnt = 0;
	stack<int>s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false) {
				visited[i][j] = true;
				s.push(j);
				s.push(i);
				cnt++;

			}
			while (!s.empty()) {
				int y = s.top();
				s.pop();
				int x = s.top();
				s.pop();				
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (!(nx < 0 || nx >= n || ny < 0 || ny >= n)) {
						if (visited[ny][nx]==false) {
							visited[ny][nx] = true;
							s.push(x);
							s.push(y);
							s.push(nx);
							s.push(ny);
							
						}
					}
				}
			}
			
			

		}
	}
	return cnt;
	
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
			if (field[i][j] > Maxh) // 빌딩의 최대 높이를 구하는 조건문
				Maxh = field[i][j];
		}
	}
	if(exection()){
		
		for (int i = 0; i <= Maxh; i++) {
			set(i); // 물의 높이에 따른 침수 셋팅
			temp[i]=dfs(); // 안전지역의 수 반환
		}
		sort(temp, temp + Maxh);
		cout << temp[Maxh - 1];
	}
	else cout << 1;
}
//https://www.acmicpc.net/problem/2468
//사소한 실수로 또 3시간 날려먹었다
//맨탈 잘잡고 집중하는 연습이 필요함
//0부터 최대 높이까지 반복문을 통해 침몰하면 방문표시를 하는 방식으로 문제 풀이함
//각각의 케이스를 하나의 배열에 담아두고 마지막에 sort()함수로 최대값 추출
//모두 같은 높이일때 반례도 처리함