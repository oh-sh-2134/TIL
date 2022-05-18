#include<iostream>

using namespace std;

int E, S, M;

void input()
{
	cin >> E >> S >> M;
}

void solution()
{
	int Year = 1;
	while (1)
	{
		if ((Year - E) % 15 == 0 && (Year - S) % 28 == 0 && (Year - M) % 19 == 0) break;
		Year++;
	}
	cout << Year;
}


int main(void)
{
	input();
	solution();

}

//https://www.acmicpc.net/problem/1476
