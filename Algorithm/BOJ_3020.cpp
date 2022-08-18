#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;

int N, H;

vector<int> top;
vector<int> bottom;

void input() {
	cin >> N >> H;
	top = vector<int>(H+1, 0);
	bottom = vector<int>(H+1, 0);
	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;
		//종유석
		if (i & 1) {
			top[H - h + 1]++;
		}
		//석순
		else {
			bottom[h]++;
		}
	}
}

void solution() {

	//누적합 계산
	for (int i = 1; i <= H; i++) {
		top[i] += top[i - 1];
		bottom[H - i] += bottom[H - i + 1];
	}

	int cnt = 0;
	int min = MAX;


	for (int i = 1; i <= H; i++) {
		//파괴 최솟값
		if (top[i] + bottom[i] < min) {
			cnt = 1;
			min = top[i] + bottom[i];
		}
		// 최솟값 구간
		else if (top[i] + bottom[i] == min) {
			cnt++;
		}
	}
	cout << min << " " << cnt;
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/3020