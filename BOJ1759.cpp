#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 15
using namespace std;

int L,C;
char arr[MAX];
vector<string>v;
void Input()
{
	cin >> L >> C;
	for (int i = 0; i < L; i++)
	{
		cin >> arr[i];
	}
}

void DFS(int i,string s)
{
	string pw = s;
	if (i == C) 
	{
		v.push_back(pw);
		return;
	}
	if (i == L)
		return;
	DFS(i, pw);
	DFS(i + 1, pw + arr[i]);
}
void soution()
{
	DFS(0,"");
}

int main(void)
{
	Input();
	soution();
	sort(v.begin(),v.end());

	for (auto e : v)
	{
		cout << e << "\n";
	}
	return 0;
}

//https://www.acmicpc.net/problem/1759
//