#include<iostream>
using namespace std;

int n;

void input() {
	cin >> n;
}

void solution() {
	int sol = 0;
	for (int i = 1; i < n; i++) {
		int sum = 0; 
		int num = i; 
		while (num != 0) { 
			//������ ���� �����
			sum += num % 10; 
			num /= 10; 
		} 
		//������ ����
		if (sum + i == n) { 
			sol = i; 
			break; 
		} 
	}
	cout << sol;
		
}
int main()
{
	input();
	solution();
}
//https://www.acmicpc.net/problem/2231