#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, A, B;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B << "\n";
	}
	return 0;
}
//https://www.acmicpc.net/problem/15552
/*
cin.tie(NULL);
ios_base::sync_with_stdio(false);
°øºÎ
*/
//https://leeeegun.tistory.com/4
//https://starrykss.tistory.com/750