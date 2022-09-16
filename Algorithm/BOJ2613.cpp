#include <iostream>
#include <vector>
using namespace std;

int N, M;
int totalSum;
vector<int> arr;
vector<int> group;

void input() {
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		totalSum += arr[i];
	}
}

bool checkMin(int target) {
	int k = 0;
	int sum = 0;
	int divCnt = 1;
	for (auto iter : arr) {
		//원소의 합이 t보다 작거나 같은 그룹을 만들어야 함
		if (sum + iter > target) {
			sum = 0;
			divCnt++;
		}
		//그룹의 원소가 M보다 크다면 최솟값을 더 증가 시킬 수 있음
		if (divCnt > M) return true;
		sum += iter;
		if (k < sum) k = sum;
	}


	//그룹의 원소 최대값이 mid보다 클경우 mid를 더 줄여야 함
	return k > target;
}

void findGroup(int n) {

	int sum = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
		if (sum > n) {
			sum = arr[i];
			M--;
			cout << cnt << " ";
			cnt = 0;
		}
		cnt++;
		//남은 원소가 남은 M의 개수와 같다면
		if (N - i == M) break;
	}
	//나머지는 1로 채움
	while (M--) {
		cout << cnt << " ";
		cnt = 1;
	}
}


int binarySearch(int l, int r) {
	while (l < r) {
		int mid = (r + l) >> 1;
		//최대값이 더 커질 수 있을때
		if (checkMin(mid)) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return r;
}

void solution() {
	int sol = binarySearch(1, totalSum);
	cout << sol << "\n";
	findGroup(sol);

}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/2613