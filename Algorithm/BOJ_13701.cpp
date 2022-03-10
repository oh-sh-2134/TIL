#include<iostream>
#include<bitset>

using namespace std;

bitset<1 << 25> bit;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	while (cin >> n) {
		if (bit[n]) continue;
		bit[n] = 1;
		cout << n << " ";
	}
}
//https://www.acmicpc.net/problem/13701