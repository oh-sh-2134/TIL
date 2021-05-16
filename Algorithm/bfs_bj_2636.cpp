#include<iostream>
#include<queue>

#define MAX 100

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int cheese[MAX][MAX];
bool visited[MAX][MAX];
int n, m, last_cheese, hours;

int CheeseCheck() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cheese[i][j] == 1) {
				cnt++;
			}
		}
	}

	if (cnt)
		last_cheese = cnt;


	return cnt;
}

void Airing()
{
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (!visited[ny][nx] && !cheese[ny][nx])
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

void Melting()
{
	queue<pair<int, int>>cheese_q;
	queue<pair<int, int>>melting_q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cheese[i][j] == 1) {
				visited[i][j] = true;
				cheese_q.push(make_pair(i, j));
				while (!cheese_q.empty())
				{
					int y = cheese_q.front().first;
					int x = cheese_q.front().second;
					cheese_q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (!cheese[ny][nx] && visited[ny][nx]) melting_q.push(make_pair(y, x));
						if (cheese[ny][nx] && (!visited[ny][nx]))
						{
							visited[ny][nx] = true;
							cheese_q.push(make_pair(ny, nx));
						}
					}
				}
			}
		}
	}
	while (!melting_q.empty())
	{
		int y = melting_q.front().first;
		int x = melting_q.front().second;
		melting_q.pop();
		cheese[y][x] = 0;
	}
}

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> cheese[i][j];
		}
	}
}

void reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}
}
int main(void) {
	Input();
	while(CheeseCheck())
	{
		reset();
		Airing();
		Melting();
		hours++;
	}

	cout << hours << "\n" << last_cheese;
}
//https://www.acmicpc.net/problem/2636
//0511 빙하문제랑 비슷하다고 생각했는데 치즈 구멍안에서는 치즈가 녹지 않는다는 점을 놓침
//0512 테두리는 치즈도 공기도 차지 않는 공간임으로 (0,0)부터 BFS를 돌려 공기 부분을 처리
//0514 각각의 기능들을 함수화 시켰고 기본 예저는 맞으나 제출시 8%에서 바운더리 에러가 나서 에러 찾아야함
//0515 접촉되어 녹이는 에어링 함수에서 공간의 크기제한을 주지않아서 바운더리 에러가 났던것 47번줄
/*문제 해결방법
필드에 치즈가 존재하는지와 치즈의 갯수를 세어줄 함수 -> CheeseCheck()
치즈 안에 있는 공기와 밖에 있는 공기의 구분할 함수 -> Airing() : 0,0에는 아무것도 없기때문에 0,0에서 시작하여 치즈를 만나기전까지 BFS로 모두 방문처리 하여 외부 공기 식별
공기와 접촉해있는 치즈를 녹이는 함수 -> Melting() : 모든치즈는 BFS를 이용해서 방문처리하고 공기와 접촉해있으면 melting_q에 넣고 방문하지 않은 치즈는 cheese_q에 넣은 후 마지막에 melting_q에 있는 치즈를 모두 녹임
치즈를 녹인 후에 구멍이 발생해서 치즈를 녹이는 공기가 추가 될 수 있음으로 Airing()을 계속하기 위해서는 reset()이 필요
*/

