#include <iostream>
#include <vector>

using namespace std;

vector<int> pizzaA;
vector<int> pizzaB;
vector<int> cntA;
vector<int> cntB;

int n;
int a, b;
int cnt;


void input() {
	cin >> n;
	cin >> a >> b;
	pizzaA.resize(a+1);
	pizzaB.resize(b+1);
	for (int i = 0; i < a; i++) {
		cin >> pizzaA[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> pizzaB[i];
	}
	cntA.resize(2000001);
	cntB.resize(2000001);
}

void func(int p, vector<int> arr, vector<int> arrCnt) {
	for (int i = 1; i <= p; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) sum += arr[j];
		arrCnt[sum]++;
		if (sum == n) cnt++;

		if (i == p) break;
		for (int j = 1; j < p; j++) {
			sum -= arr[j - 1];
			sum += arr[(j + i - 1) % p];
			arrCnt[sum]++;
			if (sum == n) cnt++;
		}
	}
}


void solution() {
	func(a, pizzaA, cntA);
	func(b, pizzaB, cntB);
	for (int i = 1; i < n; i++) {
		int j = n - i;
		cnt += cntA[i] * cntB[j];
	}
	cout << cnt;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/2632
