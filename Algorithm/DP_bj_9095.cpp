#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 14
using namespace std;

int DP[MAX];
int field[MAX];
int add[3]={1,2,3}; // +1, +2, +3
int n, m;
void solution(int n){
	queue<int>q;
	q.push(0);
	while(!q.empty()){
	int x = q.front();
	q.pop();
		for(int i=0;i<3;i++){
			if(x + add[i] <=n){
				DP[x+add[i]]++; // DP에 더햇을때 가능한 수에 해당하는 배열 카운트를 올려줌
				q.push(x+add[i]);
			}
		}
	}

}

int main(void){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> field[i];
		m = max(field[i],m); // 각수의 최대의 숫자를 구해서 12까지의 모든 수의 경우를 구하지 않게 함
	}

	solution(m);
	for(int i= 0;i<t;i++){
		cout << DP[field[i]]<<"\n";
	}
}
//https://www.acmicpc.net/problem/9095
//DP와 bfs를 이용해서 각각의 숫자에 도달하는 모든경우의 수를 구했음
// MAX 값때문에 곤혹이 있었는데 0부터 12까지 값을 저장 하려해서 13개가 필요하기때문에 MAX를 14로 줘야하는데 
//13으로줘서 계속 오답처리 됫음 
