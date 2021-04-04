#include<iostream>
#include<stack>
#include<vector>
#define MAX 21
using namespace std;

int c, r;
char field[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

/*
char alpa[26];
int MaxCnt;
int cnt;
bool go;

bool alpaCheck(char a, int n) {
	for (int i = 0; i <= n; i++) {
		if(alpa[i] == a) return false;
	}
	return true;
}

int dfs() {
	stack<int> st;
	stack<char> as;
	st.push(0);
	st.push(0);
	as.push(field[0][0]);
	while (!st.empty()) {
		go = false;
		int x = st.top();
		st.pop();
		int y = st.top();
		st.pop();
		char a = as.top();
		as.pop();
		alpa[cnt] = a;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!(nx < 0 || nx >= c || ny < 0 || ny >= r)) {
				if (alpaCheck(field[ny][nx], cnt)) {
					st.push(ny);
					st.push(nx);
					as.push(field[ny][nx]);
					go = true;
				}
			}
		}
		if (go) {
			cnt++;
			if (MaxCnt < cnt) MaxCnt = cnt;
		
		}
		else 
			cnt--;



	}
	return MaxCnt + 1;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> field[i][j];
	}
	cout << dfs();
}
 --- 처음 짠 코드인데 dfs를 이용해서 직관적으로 26의 배열에 알파벳을 하나씩 넣고 중복 되면 더 들어가지 않고 
 --- 최대 깊이까지의 수를 MaxCnt에 넣어서 구하려했는데 시간 초과가 난다.
 --- 이유는 alpaCheck 함수가 경로를 하나 찾을 때마다 for문을 한번씩 돌게 되는데 시간 복잡도가 커져서 오래걸리는 듯 해보인다
 --- 이 문제에서는 여러 코드를 참조하다 보니 아래와 같이 for문을 돌리지 않고 bool형 배열로 시간복잡도를 O(1)로 만드는 방법을 참조 함
 --- 시간복잡도 계산하는 방법과 추가적으로 메모리 계산하는 방법을 공부하고 연습이 필요해 보임
*/


bool alpa[26];
int MaxCnt;

int Max(int a, int b) { if (a > b) return a; else return b; }

void dfs(int x, int y, int cnt) {
	MaxCnt =Max(cnt, MaxCnt);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!(nx < 0 || nx >= c || ny < 0 || ny >= r)) {
			if (!alpa[field[ny][nx] - 'A']) {
				alpa[field[ny][nx] - 'A'] = true;
				dfs(nx, ny, cnt+1);
				alpa[field[ny][nx] - 'A'] = false;
			}
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> field[i][j];
	}
	for (int i = 0; i < 26; i++) {
		alpa[i] = false;
	}
	alpa[field[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << MaxCnt;
}