#include<iostream>
#include<bitset>
#include<string>

using namespace std;

bitset<21> bit;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	string s;
	int n;
	while(t--) {
		cin >> s;
		if (s == "add") {
			cin >> n;
			bit[n] = 1;
		}
		else if (s == "remove") {
			cin >> n;
			if (bit[n])
				bit[n] = 0;
		}
		else if (s == "check") {
			cin >> n;
			if (bit[n])
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (s == "toggle"){
			cin >> n;
			bit[n].flip();
		}
		else if (s == "all")
			bit.set();
		else if (s =="empty")
			bit.reset();
	
	}
}
//https://www.acmicpc.net/problem/11723