#include <iostream>

using namespace std;

int main() {
	int X;
	cin >> X;
	int ans = 0;
	while (X > 0)
	{
		if (X & 1)
			ans++;

		X >>= 1;
	}
	cout << ans;
}

//https://www.acmicpc.net/problem/1094
//비트마스킹 이용
