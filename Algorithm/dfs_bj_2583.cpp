#include<iostream>
#include<vector>
#define MAX 100

using namespace std;

bool arr[MAX][MAX];
vector<int>sol;
int n, m, k;
int x1, y1, x2, y2,c;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
	
void paint()
{
	int px = x1 > x2 ? x1 : x2;
	int qx = x1 < x2 ? x1 : x2;
	int py = y1 > y2 ? y1 : y2;
	int qy = y1 < y2 ? y1 : y2;
	for (int i = qx; i < px; i++)
	{
		for (int j = qy; j < py; j++)
		{
			arr[i][j] = true;
		}
	}

}

void Input() 
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		paint();
	}
}

void dfs(int a, int b)
{
	if (arr[a][b] == false) {
		arr[a][b] = true;
		++c;
		for (int i = 0; i < 4; i++) {
			int x = dx[i] + a;
			int y = dy[i] + b;
			if (x > 0 && y > 0 && x <= m && y <= n) {
				dfs(x, y);
			}
		}
	}
}

void solution()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c = 0;
			dfs(i,j);
			sol.push_back(c);
		}
	}
	cout << sol.size() << "\n";
	for (int i = 0; i < sol.size(); i++)
		cout << sol[i]<< " ";
}

int main(void)
{
	Input();
	solution();
}
//https://www.acmicpc.net/problem/2583
//모눈종이의 모든 점을 돌아다니며 색칠안된 부분을 dfs 돌려 vector에 넣어 처리예정
