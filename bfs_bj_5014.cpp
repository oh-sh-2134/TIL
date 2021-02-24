#include<iostream>
#include<queue>
#define MAX 1000001
using namespace std;

int s, g, f, u, d;
int h[MAX] = { 0, };
bool flag = false;


void bfs(){
	queue<int>q;
	q.push(s);
	h[s] = 1;
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		if (y == g) { // 층에 도달했을때 flag
			flag = true;
			return;
		}
		for (int i = 0; i < 2; i++) {
			int ny;

			if (i == 0)  ny = y + u;  // 올라갈 때
			else if(i == 1) ny = y - d; // 내려갈 때

			if (ny > 0 && ny <= f && h[ny]==0) { // f가 최대 높이고 1층 이상이여야 함
				q.push(ny);
				h[ny] = h[y] + 1;
			}
		}
	}
	return;
}

int main() {
	cin >> f >> s >> g >> u >> d;

	bfs();
	if (flag)cout << h[g] - 1;
	else cout << "use the stairs";
}
//https://www.acmicpc.net/problem/5014
//무난하게 풀었다.