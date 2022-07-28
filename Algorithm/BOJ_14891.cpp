#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Gear(4, vector<int>(8, 0));
vector<pair<int, int>> order;

//���� ����ϴ� �Լ�
int findScore() {
	int score = 0;
	for (int i = 0; i < Gear.size(); i++) {
		if (Gear[i][0]) {
			score = 1 << i;
		}
	}
	return score;
}

//ȸ���ؾ��ϴ��� �Ǵ��ϴ� �Լ�
bool chekTrun(int p, int c) {
	if (p > c) {
		return Gear[p][6] != Gear[c][2];
	}
	else {
		return Gear[p][2] != Gear[c][2];
	}
}

//ȸ�� ��Ű�� �Լ�
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

//state�� �ݿ��ؾ� �ҵ� bit��
//ȸ���� ó���ϴ� �Լ�
void doOrder(int n, int d) {
	vector<pair<int, int>> target;
	int pre = n;
	int preDir = d;

	//���������� Ȯ��
	for (int i = n; i < 3; i++) {
		if (i == pre) continue;
		if (!chekTrun(pre, i)) continue;
		preDir *= -1;
		target.push_back({ i, preDir });
		pre = i;
	}
	pre = n;
	preDir = d;

	//�������� Ȯ��
	for (int i = n; i >= 0; i--) {
		if (i == pre) continue;
		if (!chekTrun(pre, i)) continue;
		preDir *= -1;
		target.push_back({ i, preDir });
		pre = i;
	}

	//ȸ�� ����
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