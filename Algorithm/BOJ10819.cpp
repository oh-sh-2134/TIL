#include<iostream>
#include <algorithm>

using namespace std;

int n, i, sum, temp;
int arr[8];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution() {
	sort(arr, arr + n);

	do {
		temp = 0;
		for (i = 0; i < n - 1; i++) {
			temp += abs(arr[i] - arr[i + 1]);
		}
		sum = max(sum, temp);
	} while (next_permutation(arr, arr + n));

	cout << sum;
}

int main(void) {
	input();
	solution();
}