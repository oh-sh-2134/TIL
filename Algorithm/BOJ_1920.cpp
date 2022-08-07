#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
vector<int> A;
vector<int> B;
vector<int> sol;

void input() {
	int k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		A.push_back(k);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		B.push_back(k);
	}
}

void solution() {
	sol = vector<int>( m, 0);
	sort(A.begin(), A.end());
	for (int i = 0; i < B.size();i++) {
		int lo = 0, hi = A.size() - 1;
		while (lo  <= hi) {
			int mid = (hi+lo) / 2;

			if (A[mid] == B[i]) {
				sol[i] = 1;
				break;
			}
			
			if (A[mid]>B[i]) {
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
	}
	for (auto iter : sol) {
		cout << iter << "\n";
	}
}


int main(void) {
	input();
	solution();
}


/*
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		A.push_back(k);
	}
	sort(A.begin(), A.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		cout << (int)binary_search(A.begin(), A.end(), k)<<"\n";
	}
}
*/
//https://www.acmicpc.net/problem/1920