#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100001


int dp[MAX];
int maxval;
int n, k;
int v[101], w[101];

void Input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}
}

void solution()
{
	for (int i = 1; i <=n; i++)
	{
		for (int j = k; j > 1 ; j--)
		{
			if (w[i] <= j)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

		}
	}
	cout << dp[k];

}

int main(void)
{
	Input();
	solution();
}


//acmicpc.net/problem/12865
//받은 배열을 정렬해서 dp로 풀면 될것같음

//손코딩 후 다른사람들 코드를 참고 했는데 01 KnapSack 알고리즘 문제임 01 KnapSack알고리즘도 모르고 얼추 비슷하게 풀어서 관련내용 확인필요할듯.. 회사라 코드는  
