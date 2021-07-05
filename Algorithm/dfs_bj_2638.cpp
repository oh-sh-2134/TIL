#include<iostream>
#include<queue>
#define MAX 100

#define Cheese 1
#define Air 0
#define MeltedAir -1
#define MeltCheese 3
using namespace std;


int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int m, n, cnt;
int arr[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>>q;
queue<pair<int, int>>melt_q;
queue<pair<int, int>>non_melt_q;

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

void Airing(int a, int b)
{
	q.push(make_pair(a, b));
	arr[a][b] = MeltedAir;
	visited[a][b] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (x < 0 || y < 0 || x >= m || y >= n) continue;
			if (arr[ny][nx] == Air && !visited[ny][nx])
			{

				visited[ny][nx] = true;
				arr[ny][nx] = MeltedAir;
				q.push(make_pair(ny, nx));
			}

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
			if (arr[i][j] == Cheese)
			{
				flag = true;
				return flag;
			}
		}
	}
	return flag;
}


void dfs(int a, int b)
{
	if (arr[a][b] >= Cheese && !visited[a][b])
	{
		visited[a][b] = true;
		for (int i = 0; i < 4; i++)
		{
			int y = a + dy[i];
			int x = b + dx[i];
			if (x < 0 || y < 0 || x >= m || y >= n) continue;
			if (arr[y][x] == MeltedAir) arr[a][b]++;
			if (arr[y][x] >= Cheese && !visited[y][x])
				dfs(y, x);
		}
	}

}

void bfs(int a, int b)
{
	visited[a][b] = true;
	q.push(make_pair(a, b));
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{

			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

			if (arr[ny][nx] == MeltedAir)
			{
				arr[y][x]++;
			}
			if (arr[ny][nx] == Cheese && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}

		if(arr[y][x] < MeltCheese)
			non_melt_q.push(make_pair(y,x));
		else
			melt_q.push(make_pair(y, x));
	}

}

void MeltingCheese()
{
	int mcnt, vcnt;
	mcnt = melt_q.size();
	vcnt = non_melt_q.size();

	for(int i=0; i<mcnt; i++)
	{
		Airing(melt_q.front().first, melt_q.front().second);
		melt_q.pop();
	}

	for(int i = 0; i< vcnt; i++)
	{
		arr[non_melt_q.front().first][non_melt_q.front().second] = Cheese;
		visited[non_melt_q.front().first][non_melt_q.front().second] = false;
		non_melt_q.pop();
	}
}


void solution()
{
	int sol = 0;
	Airing(0, 0);
	while (CheesCheck())
	{
		sol++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == Cheese && !visited[i][j])
					bfs(i, j);
			}
		}
		MeltingCheese();

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
//20210701 에어링을 최초 1회후 녹은 치즈 기준으로만 돌리면 될 것 같음, 오답처리되는 원인을 찾아야함
//20210702 고민했었던 방법대로 했지만 9퍼에서 시간초과 되어 bfs도 만들어봤는데 마찬가지 연산 횟수를 줄이는 방법을 생각해야함
//20210703 치즈 체크에서 연산이 너무 많은것같음 , 코드수정 , 치즈위치 visited 초기화 
//20210705 바운더리 에러남 queue 초기화 문제인듯한데 확인이 필요할듯
