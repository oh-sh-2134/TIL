#include<iostream>
#include<vector>
#include<string>


using namespace std;
vector<int> failtable(string pattern) {
	int patternsize = pattern.size();
	int j = 0;
	vector<int>table(patternsize, 0);
	for (int i = 1; i < patternsize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j-1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

int main() {
	freopen("test.txt", "r", stdin);
	int L;
	string pattern;
	cin >> L>>pattern;
	
	vector<int>table = failtable(pattern);
	cout << L - table[L - 1];

}

//https://www.acmicpc.net/problem/1305
//이해가 조금 안되는 부분이 있는것 같다.