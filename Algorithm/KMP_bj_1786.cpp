#include<iostream>
#include<vector>
#include<string>
using namespace std;



vector<int> failtable(string pattern) {
	int j = 0, patternsize=pattern.size();
	vector<int>table(patternsize, 0);
	for (int i = 1; i < patternsize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j-1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	cout << "failtable"<<endl;
	for (int i = 0; i < patternsize; i++) {
		cout << table[i];
	}
	cout << "" << endl;
	return table;
}
void KMP(string pattern, string text) {
	int j = 0,patternsize=pattern.size(),textsize=text.size(),cnt=0;
	vector<int>table = failtable(pattern);
	vector<int>soltable(textsize,0);
	for (int i = 0; i < textsize; i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (patternsize-1  == j) {
				soltable[0]= ++cnt;
				soltable[cnt] = i - patternsize + 2;
				j = table[j];
			}
			else
				j++;
		}
		cout << j;
	}
	cout << " "<< endl;
	cout << soltable[0]<<endl;
	for (int i = 1; i <= soltable[0]; i++) {
		cout << soltable[i]<<" ";
	}
}

int main() {
	string pattern, text;
	
	getline(cin, text);
	getline(cin, pattern);

	KMP(pattern,text);
}
//https://www.acmicpc.net/problem/1786
// 사실 그냥 KMP 알고리즘을 다시 푸는건데 실패 테이블만 만들다가 탐색까지 하는 
// 알고리즘을 다시짜니까 헷갈려서 엄청 많이 틀렸다
// 다시한번 복습을 철저히 해야한다는 것을 느낌