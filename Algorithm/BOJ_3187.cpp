#include<iostream>
#include<queue>
#define MAX 250

using namespace std;

char field[MAX][MAX];
bool visited[MAX][MAX];
int vk[2][2];
// v count = vk[0][0]
// k count = vk[1][0]
// total == vk[][1]

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;


void Input() {
	char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			field[i][j] = c;
		}
	}
}

void bfs(int a, int b)
{
	queue<pair<int, int>>q;
	q.push(make_pair(a, b));
	visited[a][b] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (field[ny][nx] != '#' && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				cout << field[ny][nx] << "\n";
				if (field[ny][nx] == 'v')
				{
					vk[0][0]++;
				}
				if (field[ny][nx] == 'k')
				{
					vk[1][0]++;
				}
				q.push(make_pair(ny, nx));
			}
		}
	}

	cout << vk[0][0] << " " << vk[0][1] << " " << vk[1][0] << " " << vk[1][1] << "\n";
	if (vk[0][0] < vk[1][0])
		vk[0][0] = 0;
	else
		vk[0][0] = 0;
	vk[0][1] += vk[0][0];
	vk[1][1] += vk[1][0];
}


int main() {
	memset(field, '#', sizeof(field));
	Input();
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (field[i][j] != '#' && !visited[i][j])
			{
				bfs(i, j);
			}
		}
	}
	cout << vk[0][1] << " " << vk[1][1];
}
//https://www.acmicpc.net/problem/3187