#include<iostream>
#define MAX 1000

using namespace std;

int N;
void Input() {
	cin >> N;
}

int solution(int n) {
	int cnt = 0;

	if (n < 10)
		return n;
	else if (n < 100)
	{
		for (int i = 1; i < n/10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if ((i - j) >= 0)
				{
					if ((i * 10 + (i-j)) <= n)
						cnt++;
				}

				if ((i + j) < 10)
				{
					if ((i * 10 + (i+j)) <= n)
						cnt++;
				}
					
			}
		}
		return (cnt + 9);
	}
	else
	{
		for (int i = 1; i < n / 100; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if ((i - 2*j) >= 0)
				{
					if ((i * 100 + (i - j) * 10 + (i - 2 * j)) <= n)
						cnt++;
					cout << (i * 100 + (i - j) * 10 + (i - 2 * j)) << "\n";
				}

				if ((i + 2*j) < 10 && j!=0)
				{
					if ((i * 100 + (i+j)*10 + (i+2*j)) <= n)
						cnt++;
				}
				cout << (i * 100 + (i + j) * 10 + (i + 2 * j)) << "\n";

			}
		}
		return (cnt + 90 + 9);
	}

	return cnt;
}

int main(void)
{
	Input();
	int sol = solution(N);

	cout << sol;

	return 0;
}