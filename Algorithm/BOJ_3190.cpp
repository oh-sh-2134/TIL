#include<iostream>
#include<queue>
#include<vector>

using namespace std;

enum {
	none = 0,
	apple = 1,
	snake = 2
};

class point {
public :
	int y;
	int x;
	int dirc;
	point(int a, int b, int c) {
		x = a;
		y = b;
		dirc = c;
	}
};

// 오른쪽, 아래, 왼쪽, 위
int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,1,0,-1 };

vector<point> snakes;
vector<vector<int>> field;
queue<pair<int, char>> order;

int N, K, L, X;
char C;

vector<vector<int>> setField(int n) {
	return vector<vector<int>>(n+1, vector<int>(n+1, 0));
}

void input() {
	cin >> N;
	field = setField(N);
	cin >> K;
	int x, y;
	for(int i=0;i<K;i++){
		cin >> y >> x;
		field[x][y] = apple;
	}
	cin >> L;
	for(int i=0;i<L;i++){
		cin >> X;
		cin >> C;
		order.push({ X,C });
	}
}

void solution() {
	int time = 0;
	
	snakes.push_back(point(1, 1, 0));
	field[1][1] = snake;
	while (snakes.size()) {

		//방향이 바뀔때
		if (order.size() != 0 && time == order.front().first) {

			//오른쪽
			if (order.front().second == 'D') {
				snakes[0].dirc = snakes[0].dirc != 3 ? snakes[0].dirc + 1 : 0;
			}
			//왼쪽
			else {
				snakes[0].dirc = snakes[0].dirc != 0 ? snakes[0].dirc - 1 : 3;
			}
			order.pop();
		}

		time++;
		
		//뱀이 움직이는 로직
		
		point p = snakes[0];
		

		//벽에 머리를 박음
		if (p.x + mx[p.dirc] > N || p.x + mx[p.dirc] <= 0 || p.y + my[p.dirc] > N || p.y + my[p.dirc] <= 0) {
			cout << time;
			return;
		}

		//몸통에 머리를 박음
		if (field[p.x + mx[p.dirc]][p.y + my[p.dirc]] == snake) {
			cout << time;
			return;
		}

		//사과 먹을때
		if (field[p.x + mx[p.dirc]][p.y + my[p.dirc]] == apple) {
			field[p.x + mx[p.dirc]][p.y + my[p.dirc]] = snake;
			snakes.insert(snakes.begin(),point(p.x + mx[p.dirc], p.y + my[p.dirc], snakes[0].dirc));
			continue;
		}
		

		//지나갈수 있을때
		//몸통이 없다면
		if (snakes.size() == 1) {
			field[p.x][p.y] = none;
			field[p.x + mx[p.dirc]][p.y + my[p.dirc]] = snake;
			snakes.push_back(point(p.x + mx[p.dirc], p.y + my[p.dirc], snakes[0].dirc));
			snakes.erase(snakes.begin());
			
		}
		//몸통이 있다면
		else {
			field[p.x + mx[p.dirc]][p.y + my[p.dirc]] = snake;
			field[snakes[snakes.size()-1].x][snakes[snakes.size() - 1].y] = none;
			snakes.insert(snakes.begin(), point(p.x + mx[p.dirc], p.y + my[p.dirc], snakes[0].dirc));
			snakes.erase(snakes.end()-1);
		}
		
	}
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/3190