#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 100001

using namespace std;


vector<pair<int, int>> arr;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second < b.second)
		return true;
	else if (a.second == b.second) {
		if (a.first < b.first)
			return true;
	}
	return false;
}
void Input() {
	int a,x,y;
	cin >> a;
	while (a--) {
		cin >> x >> y;
		arr.push_back({ x,y });
	}
}

void solution() {
	sort(arr.begin(), arr.end(),cmp);
}

int main(void) {
	Input();
	solution();
	for (auto itor : arr) 
		cout << itor.first << " " << itor.second << "\n";
	
}
//https://www.acmicpc.net/problem/11651