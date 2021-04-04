#include<iostream>
#include<vector>


using namespace std;

vector<int> maketable(string pattern) {
	int patternsize = pattern.size(),j=0;
	vector<int>table(patternsize, 0);
	for (int i = 1; i < patternsize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}
void KMP(string pattern, string text) {
	vector<int>table = maketable(pattern);
	int j = 0;
	for (int i = 0; i < text.size(); i++) {
		while (j > 0 && pattern[j] != text[i]) {
			j = table[j];
		}
		if (pattern[j] == text[i]) {
			if (j == pattern.size() - 1) {
				cout << i - pattern.size() + 2 << "번째에서 발견" << endl;
				j = table[j];
			}
			j++;
		}		
	}
}

int main() {
	string pattern = "abacaba";
	string text = "abasdaseabacabaasee";
	vector<int> table= maketable(pattern);
	for (int i = 0; i < pattern.size(); i++) {
		cout << table[i]<<endl;
	}
	KMP(pattern, text);

}