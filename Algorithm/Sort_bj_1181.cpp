#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}
int main() {

	vector <string> a;
	string temp;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		a.push_back(word);
	}

	sort(a.begin(), a.end(), compare);

	for (int i = 0; i < N; i++) {
		if (temp == a[i])continue;
		cout << a[i] << '\n';
		temp = a[i];
	}
	return 0;
}
//https://www.acmicpc.net/problem/1181
//compare함수 이용해서 sort

