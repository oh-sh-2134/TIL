#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


#define nMAX 101
#define wMAX 10001

int arr[nMAX][nMAX];
vector<pair<int,int>> v;
pair<int,int>p;
int dp[wMAX];
int n;
int v,w;

void Input()
{
	cin >>n;
	for(int i=0; i<=n;i++)
	{
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	sort(v.begin,v.end);

}

void solution()
{
	for(int i=0;i<=n;i++)
	{
		if(dp[v[i].first] == 0) dp[v[i].first] = dp[v[i-1].second];
		dp[v[i].first] = max(max(dp[v[i].first],v[i].second),v[i].second+dp[n-v[i].first]);
	}
	cout << dp[v[n].first];

}

int main(void)
{
	Input();
	solution();
}

//acmicpc.net/problem/12865
//받은 배열을 정렬해서 dp로 풀면 될것같음
//손코딩 후 다른사람들 코드를 참고 했는데 01 KnapSack 알고리즘 문제임 01 KnapSack알고리즘도 모르고 얼추 비슷하게 풀어서 관련내용 확인필요할듯.. 회사라 코드는  
