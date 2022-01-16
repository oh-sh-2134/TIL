#include<iostream>
#define MAX 31
using namespace std;


int d, k;

int A[MAX];
int B[MAX];

void Input() {
	cin >> d >> k;
}

void solution() {
	A[1] = 1;
	A[2] = 0;
	B[1] = 0;
	B[2] = 1;
	for (int i = 3; i <= d; i++)
	{
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}

	for (int i = 1; i <= k; i++)
	{
		int Spare = k - (A[d] * i);
		if (Spare % B[d] == 0)
		{
			cout << i << endl << Spare / B[d] << endl;
			return;
		}
	}
}

int main(void) {
	Input();
	solution();
}

//https://www.acmicpc.net/problem/2502