#include<iostream>
#define MAX 1000000
using namespace std;

int n,s,sum,cnt;
int arr[MAX];

void Input()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void DFS(int i, int sum)
{
	if (i == n)
		return;
	if (sum + arr[i] == s) 
		cnt++;

	DFS(i + 1, sum);
	DFS(i + 1, sum + arr[i]);
}
void soution()
{
	DFS(0, 0);
}

int main(void)
{
	Input();
	soution();

	cout << cnt;
	return 0;
}

//https://www.acmicpc.net/problem/1182
//난이도가 DFS와 재귀를 이용 어려워서 블로그 참조함