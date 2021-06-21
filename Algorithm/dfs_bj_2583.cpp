#include<iostream>
#include<vector>
#define MAX 100

using namespace std;

bool arr[MAX][MAX];
vector<int>sol;
int n, m, k;
int x1, y1, x2, y2;

void paint()
{
	int px = x1 > x2 ? x1 : x2;
	int qx = x1 < x2 ? x1 : x2;
	int py = y1 > y2 ? y1 : y2;
	int qy = y2 < y2 ? y1 : y2;
	for (int i = qx; i < px; i++)
	{
		for (int j = qy; j < py; j++)
		{
			arr[j][i] = true;
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

void dfs()
{
	
}

void solution()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{

		}
	}
}

int main(void)
{
	Input();
	solution();
}
//https://www.acmicpc.net/problem/2583
//모눈종이의 모든 점을 돌아다니며 색칠안된 부분을 dfs 돌려 vector에 넣어 처리예정