#include<iostream>
#define MAX 1000
using namespace std;

int R,C;
int field[MAX][MAX];

void Input()
{
	cin >> R >> C;
	for(int i=0; i<R; i++)
	{
		for(int j=0;j<C;j++)
		{
			cin >> field[i][j];
		}
	}
}

void solution()
{



}

int main(void){
	Input();


}
//https://www.acmicpc.net/problem/4179
//우선큐에 넣어야 할 것을 찾아야함