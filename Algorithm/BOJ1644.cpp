#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> checkPrime;
vector<int> prime;
void input() {
	cin >> n;
	checkPrime.resize(n + 1,1);
}

//에라토스테네스의 체
void findPrime(int num) {
	for (int i = 2; i*i <= n; i++) {
		if (checkPrime[i] == 0) continue;
		for (int j = i + i; j <= n; j += i) {
			checkPrime[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (checkPrime[i]) 
			prime.push_back(i);
	}
}

void solution() {
	findPrime(n);
	int start = 0;
	int end = 0;
	int sum = 0;
	int cnt = 0;
	//투포인트
	while (1) {
		//n보다 작다면 startPoint 증가
		if (sum > n) {
			sum -= prime[start];
			start++;
			continue;
		}
		// n보다 크다면 endPoint 증가
		if (sum < n) {
			if (end >= prime.size()) break;
			sum += prime[end];
			end++;
			continue;
		}
		//n과 같다면 카운팅
		cnt++;
		if (end >= prime.size()) break;
		sum += prime[end];
		end++;
	}
	cout << cnt;
}

int main(void) {
	input();
	solution();
}

//https://www.acmicpc.net/problem/1644