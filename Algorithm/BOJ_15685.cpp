#include<iostream>
using namespace std;

int x, y, d, g;
int N;
int answer, curve_size;
int curve[1025];
int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,-1,0,1 };
int field[101][101];

void findDragonSquare() {
	for (int Y = 0; Y < 100; Y++) {
		for (int X = 0; X < 100; X++) {
			if (field[Y][X] == 1 && field[Y + 1][X] == 1 && field[Y][X + 1] == 1 && field[Y + 1][X + 1] == 1)
				answer++;
		}
	}

}

void make_map(int x, int y) {
	for (int i = 0; i < curve_size; i++) {
		x += mx[curve[i]];
		y += my[curve[i]];
		if (x < 0 || x > 100 || y < 0 || y > 100) continue;
		field[y][x] = 1;
	}

}

void make_curve(int d, int g) {
	curve_size = 0;
	curve[curve_size++] = d;
	for (int i = 0; i < g; i++) {
		for (int j = curve_size - 1; j >= 0; j--) {
			curve[curve_size++] = (curve[j] + 1) % 4;
		}
	}

}

int main() {

	cin >> N;

	for (int n = 0; n < N; n++) {
		cin >> x >> y >> d >> g;
		make_curve(d, g);
		make_map(x, y);
		field[y][x] = 1;
	}
	findDragonSquare();
	cout << answer;
}
//https://www.acmicpc.net/problem/15685