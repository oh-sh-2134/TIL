#include<iostream>
using namespace std;

int n;

void input() {
	cin >> n;
}

void solution() {
	int sol;
	int cnt = 0;
	int temp;
	while (cnt != n)
	{
		sol++;
		temp = sol;
		while (temp != 0)
		{
			//종말의 수 체크
			if (temp % 1000 == 666) 
			{
				cnt++;
				break;
			}
			//자리수 줄이기
			temp /= 10; 
		}
	}
	cout << sol;
}
int main()
{
	input();
	solution();
}
//https://www.acmicpc.net/problem/1436