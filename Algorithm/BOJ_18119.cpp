#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> words;

int convertWordsToBit(string s) {
	int bit = 0;
	for (auto c : s) 
		bit |= (1 << (c - 'a'));
	return bit;
}

void solution() {
	int n, m;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		words.push_back(convertWordsToBit(s));
	}
	int o;
	char x;
	int bit = 0;
	for (int i = 0; i < 26; i++) {
		bit |= (1 << i);
	}
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		cin >> o >> x;

		if (o == 1)
			bit &= ~(1 << x - 'a');
		else
			bit |= (1 << x - 'a');
		for (auto s : words) {
			if ((s & bit) == s)
				cnt++;
		}
		cout << cnt << "\n";
	}
}

int main(void) {
	solution();
}
//https://www.acmicpc.net/problem/18119
// Time Comlexity 1000x10000x10000 -> 1000x10000