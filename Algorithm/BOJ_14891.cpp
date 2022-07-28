#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Gear(4, vector<int>(8, 0));
vector<pair<int, int>> order;

//점수 계산하는 함수
int findScore() {
	int score = 0;
	for (int i = 0; i < Gear.size(); i++) {
		if (Gear[i][0]) {
			score = 1 << i;
		}
	}
	return score;
}

//회전해야하는지 판단하는 함수
bool chekTrun(int p, int c) {
	if (p > c) {
		return Gear[p][6] != Gear[c][2];
	}
	else {
		return Gear[p][2] != Gear[c][2];
	}
}

//회전 시키는 함수
void turn(int n, int d) {
	if (d == 1) {
		Gear[n].insert(Gear[n].begin(), Gear[n].back());
		Gear[n].pop_back();
	}
	else {
		Gear[n].push_back(Gear[n].front());
		Gear[n].erase(Gear[n].begin());
	}
}

//state를 반영해야 할듯 bit로
//회전을 처리하는 함수
void doOrder(int n, int d) {
	vector<pair<int, int>> target;
	int pre = n;
	int preDir = d;

	//오른쪽으로 확인
	for (int i = n; i < 3; i++) {
		if (i == pre) continue;
		if (!chekTrun(pre, i)) continue;
		preDir *= -1;
		target.push_back({ i, preDir });
		pre = i;
	}
	pre = n;
	preDir = d;

	//왼쪽으로 확인
	for (int i = n; i >= 0; i--) {
		if (i == pre) continue;
		if (!chekTrun(pre, i)) continue;
		preDir *= -1;
		target.push_back({ i, preDir });
		pre = i;
	}

	//회전 수행
	for (auto iter : target) {
		turn(iter.first, iter.second);
	}
}

void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char a;
			cin >> a;
			Gear[i][j] = a - '0';
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		order.push_back({ a,b });
	}
}


void solution() {
	for (auto iter : order) {
		int gear = iter.first;
		int dir = iter.second;
		doOrder(gear, dir);
	}
	int sol = findScore();
	cout << sol;
}

int main() {
	input();
	solution();
}
//https://www.acmicpc.net/problem/14891