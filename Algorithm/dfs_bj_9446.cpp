#include<iostream>

#define MAX 100001
using namespace std;

int arr[MAX];
bool visited[MAX];  // 노드의 방문 유무
bool done[MAX];     // 노드의 재방문 유무
int T, n, cnt;

void dfs(int Current)
{
	visited[Current] = true;
	int Next = arr[Current];
	if(!visited[Next]) // 다음 노드가 방문되었는지 확인
		dfs(Next);
	else if(!done[Next]){
		for(int i = Next; i != Current; i = arr[i])	// 팀을 이루는 사람의 숫자를 카운팅
			cnt++;
		cnt++; // 자기 자신도 카운팅
	}

	done[Current] = true; // 현제 노드를 확실히 방문하지 않음을 확인
}

void solution()
{
	for(int i = 1; i<=n; i++)
	{
		if(!visited[i])
			dfs(i);
	}
	cout << n - cnt<<"\n";
}

void Input()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			visited[i] = false;
			done[i] = false;
		}
		cnt = 0;
		solution();
	}
}

int main(void){
	Input();
}
//https://www.acmicpc.net/problem/9466
//dfs를 돌긴해야하는데 아이디어 안떠오름
//다음 방문할 노드는 arr[Next]가 아닌 Next로 가야함, + cnt 초기화 해야함
//학생을 노드라고 봤을때 1번 부터 dfs로 더이상 방문할 수 없을때 까지 방문을 한 뒤 팀(노드끼리 하나의 Circle을 이루는 수)를 cnt하여 전체 숫자에서 빼면 팀을 이루지 못한 사람을 찾을 수 있음 
