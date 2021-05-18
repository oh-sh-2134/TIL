#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 500

using namespace std;

int n;
int dp[102];
vector<pair<int, int>> v;

int max(int a, int b) {
	return a > b ? a : b;
}

int solution() { // 정련된 전깃줄의 반대편의 증가하는 최대길이의 수를 구하는 dp식
	int sol = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				if (dp[j] >= dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		sol = max(sol, dp[i]);
	}
	return sol;
}

void Input() { // 전깃줄을 입력받고 정렬까지 함
	int a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	sort(v.begin(), v.end());
}

int main(void) {
	
	Input();
	cout << n - solution();
}
//https://www.acmicpc.net/problem/2565
//0517 전깃줄을 A와 B로 나누고 차례로 비교해나가며 곂치는걸 지우는 방식을 생각
//0518 검색을 통해 아이디어 참고 , 전기줄 A B중 하나를 정렬 후에 반대편 전깃줄의 증가하는 최대길이의 수를 구하여 n에서 빼면 잘라야 하는 최소의 길이를 구 할 수 있음
