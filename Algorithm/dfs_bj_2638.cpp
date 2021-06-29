#include<iostream>
#include<queue>
#define MAX 100

#define Cheese 1
#define Air 0
#define MeltedAir -1

using namespace std;


int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int m, n, cnt;
int arr[MAX][MAX];
bool visted[MAX][MAX];


void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
}

bool CheesCheck()
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (arr[i][j] >= Cheese)
			{
				flag = true;
				arr[i][j] = Cheese;
			}
			else 
				arr[i][j] = Air;

			visted[i][j] = false;
		}
	}
	return flag;
}

void Airing()
{
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	arr[0][0] = MeltedAir;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (x < 0 || y < 0 || x >= m || y >= n) continue;
			if (arr[ny][nx] == 0) arr[ny][nx] = MeltedAir;

		}
	}

}

void dfs(int a, int b)
{
	if (arr[a][b] >= Cheese && !visted[a][b])
	{
		visted[a][b] = true;
		for (int i = 0; i < 4; i++)
		{
			int y = a + dy[i];
			int x = b + dx[i];
			if (x < 0 || y < 0 || x >= m || y >= n) continue;
			if (arr[y][x] == MeltedAir) arr[a][b]++;
			if (arr[y][x] >=Cheese) dfs(y, x);
		}
	}

}

void solution()
{
	int sol = 0;
	while (CheesCheck())
	{
		sol++;
		Airing();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] >= Cheese && !visted[i][j])
					dfs(i, j);
			}
		}

	}
	cout << sol;
}

int main(void)
{
	Input();
	solution();
}

//https://www.acmicpc.net/problem/2638
//이전 치즈 문제랑 차이점은 공기에 닿는 면이 2개 이상일때 녹는다는 점
//현제 녹는 공기를 정의하는 함수, 치즈가 존재하는지 확인하는 함수 만듬 dfs와 solution함수 수정해야함
//시간초과 나옴 원인 파악필요
