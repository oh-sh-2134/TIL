#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


#define MAX 100001


int dp[MAX][2];
int maxval;
int n,k;
int v,w;

void Input()
{
	cin >>n>>k;
	for(int i=0; i<n;i++)
	{
		cin >> v >> w;
		dp[v][1] = w;
	}
}

void solution()
{
	for(int i=1;i<=k;i++)
	{
		for(int j = i-1; j>=i/2; j--)
		{
			dp[i][0] = max(dp[i-j][0] + dp[j][0], dp[i][0]);

		}
		dp[i][0] = max(dp[i][0],dp[i][1]);
		maxval = max(maxval,dp[i][0]);
	}
	cout << maxval;

}

int main(void)
{
	Input();
	solution();
}

//acmicpc.net/problem/12865
//받은 배열을 정렬해서 dp로 풀면 될것같음

//손코딩 후 다른사람들 코드를 참고 했는데 01 KnapSack 알고리즘 문제임 01 KnapSack알고리즘도 모르고 얼추 비슷하게 풀어서 관련내용 확인필요할듯.. 회사라 코드는  
