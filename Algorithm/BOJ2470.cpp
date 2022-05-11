#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
int n;

int abs(int a) {
	return a >= 0 ? a : a * (-1);
}
void input() {
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
}

void solution() {
	//오름차순으로 정렬하여
	sort(arr.begin(), arr.end());
	int sum = 0;
	int minIdx = 2000000001;
	int sp=0, ep = arr.size()-1;
	int p1, p2;
	//투포인터 알고리즘 사용
	while (sp < ep) {
		if (abs(arr[sp] + arr[ep]) <= minIdx) {
			p1 = arr[sp];
			p2 = arr[ep];
			minIdx = abs(arr[sp] + arr[ep]);
		}
		if (arr[sp] + arr[ep] < 0) {
			sp++;
			continue;
		}
		ep--;

	}
	cout << p1 << " "<< p2;
}

int main(void) {
	input();
	solution();
}

//https://www.acmicpc.net/problem/2470