#include<iostream>
#define MAX 31

using namespace std;

int l, r;

int sol() {
	int idx = 1;
	int a = r;
	int b = 1;
	int c = l;
	while (c > 0) {
		idx = idx * a / b;
		a--;
		b++;
		c--;
	}

	return idx;
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		if (l == r) cout << 1 << "\n";
		else cout << sol() << "\n";
	}
}
//https://www.acmicpc.net/problem/1010
//가만히 보자하니 콤비네이션 알고리즘이네 ;; DP로 풀기위해서 각 DP에 인덱스의 팩토리얼 숫자들을 넣어주고
//왼쪽 사이드 l 과 오른쪽 사이드 r을 받아서 DP[r]/(DP[l]*DP[l-r]) 으로 바로바로 답을 출력하려 했는데 
//팩토리의 숫자가 21만해도 20자리가 되어버려서 long long 으로 받을 수 없게 됨
//그래서 예시에 있는 13 29 를 해결할때 바로바로 나누어주는 방식을 사용했음
//DP로 풀기위해 점화식을 세우는 방법도 찾아보고 익혀야겠음