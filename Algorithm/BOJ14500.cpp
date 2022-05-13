#include <iostream>
#include <vector>
#define MAX 501
using namespace std;

int arr[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
int sol;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0,0 };

class point {
public :
	point(int Y, int X) {
		x = X;
		y = Y;
	}
	int x;
	int y;
};

//폴리오미노는 ㅗ모양을 제외하면 3depth를 가지기 때문에 dfs로 풀 수 있음
void dfs(point p, int sum, int cnt) {
	if (cnt == 3) {
		if (sol < sum)
			sol = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int y = p.y + dy[i];
		int x = p.x + dx[i];
		if (y >= n || y < 0 || x >= m || x < 0) continue;
		if (visited[y][x]) continue;
		visited[y][x] = true;
		dfs(point(y, x), sum + arr[y][x], cnt + 1);
		visited[y][x] = false;
	}
}

//ㅗ모양의 4가지 방향
void parts1(int y, int x)
{
	int sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x - 1];
	if (sum > sol) sol = sum;
	
}

void parts2(int y, int x)
{
	int sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x + 1];
	if (sum > sol) sol = sum;
}

void parts3(int y, int x)
{
	int sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1];
	if (sum > sol) sol = sum;
}

void parts4(int y, int x)
{
	int sum = arr[y][x] + arr[y+1][x- 1] + arr[y+1][x] + arr[y + 1][x + 1];
	if (sum > sol) sol = sum;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
}


void solution() {
	
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfs(point(i, j), arr[i][j], 0);
			if (j - 1 >= 0 && i + 2 < n) parts1(i, j);
			if (i + 2 < n && j + 1 < m) parts2(i, j);
			if (j + 2 < m && i + 1 < n) parts3(i, j);
			if (j + 1 < m && j - 1 >= 0 && i + 1 < n) parts4(i, j);
			visited[i][j] = false;
		}
	}
	cout << sol;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/14500