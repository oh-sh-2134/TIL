#include<iostream>
#include<string>


using namespace std;

int main(void) {
	int n, r;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> r >> s;
		for (int a = 0; a < s.size(); a++) {
			for (int j = 0; j < r; j++) {
				cout << s[a];
			}
		}
		cout << "\n";
	}
}
//https://www.acmicpc.net/problem/2675
//no comment