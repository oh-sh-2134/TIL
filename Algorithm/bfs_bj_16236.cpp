#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>

#define endl "\n"
#define MAX 20
using namespace std;

typedef struct
{
	int x;
	int y;
	int Size;
	int Eat_Num;
	int Time;
}Shark;

typedef struct
{
	int x;
	int y;
	int Dist;
}Food;


int N;
int arr[MAX][MAX];
bool visited[MAX][MAX];

Shark S;
vector<Food> V;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1 ,-1 ,0 ,0 };


void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 9)
			{
				S.x = i;
				S.y = j;
				S.Size = 2;
				S.Eat_Num = 0;
				S.Time = 0;
			}
		}
	}
}

void BFS(int a, int b)
{
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(a, b), 0));
    visited[a][b] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Dist = Q.front().second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continuew;
            
            if (!visited[nx][ny])
            {
                if (arr[nx][ny] == 0)
                {
                    visited[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), Dist + 1));
                }
                else if (arr[nx][ny] < S.Size)
                {
                    Food Temp;
                    Temp.x = nx;
                    Temp.y = ny;
                    Temp.Dist = Dist + 1;
 
                    V.push_back(Temp);
                    visited[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), Dist + 1));
                }
                else if (arr[nx][ny] == S.Size)
                {
                    visited[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), Dist + 1));
                }
            }
            
        }
    }
}


int main(void)
{
	
}
//https://www.acmicpc.net/problem/16236
/*
접근 아기상어의 크기와 좌표를 동시에 저장해야 될것 같음
가장 가까이에 있는 물고기를 먹는데 어떤 크기에 따라 먹는지도 정확한 이해가 필요

0608
너무 어려워서 설명을 보고 클론 코딩...
https://yabmoons.tistory.com/160

*/
