#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

#define INF 1e8+10
using namespace std;

int d[205][205];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = INF;

	for (int i = 1; i <= n; i++)
		fill(d[i], d[i] + 1 + n, INF);

	for (auto element : fares)
	{
		d[element[0]][element[1]] = element[2];
		d[element[1]][element[0]] = element[2];
	}

	for (int i = 1; i <= n; i++)
		d[i][i] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		answer = min(answer, d[s][i] + d[i][a] + d[i][b]);
	}
	
	return answer;
}

int main(void)
{
	vector<vector<int>> v = { {4, 1, 10},{3, 5, 24},{5, 6, 2},{3, 1, 41},{5, 1, 24},{4, 6, 50},{2, 4, 66},{2, 3, 22},{1, 6, 25} };
	cout << solution(6, 4, 6, 2, v);
}