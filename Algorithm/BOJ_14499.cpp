#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> field;
vector<int> orders;
int N, M, X, Y, C;

enum {
	EAST = 1,
	WEST = 2,
	NORTH = 3,
	SOUTH = 4
};

//주사위의 면과 행위가 정의된 클래스
class Dice {
private:
	int y;
	int x;
	int back = 0;
	int front = 0;
	int up = 0;
	int down = 0;
	int right = 0;
	int left = 0;

public:

	Dice() {
	}

	Dice(int a, int b) {
		y = a;
		x = b;
	}

	//주사위의 이동이 가능한지 확인
	bool canMove(int dirc) {
		if (dirc == EAST) {
			return (x + 1 < M);
		}

		else if (dirc == WEST) {
			return (x - 1 >= 0);
		}

		else if (dirc == NORTH) {
			return (y - 1 >= 0);
		}

		else if (dirc == SOUTH) {
			return (y + 1 < N);
		}

		return false;
	}

	void move(int dirc){

		if (dirc == EAST) {
			moveEast();
		}
		
		else if (dirc == WEST) {
			moveWest();
		}
		
		else if (dirc == NORTH) {
			moveNorth();
		}
		
		else if (dirc == SOUTH) {
			moveSouth();
		}
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void setBack(int n) {
		back = n;
	}

	int getFront() {
		return front;
	}

	int getBack() {
		return back;
	}

	//북
	void moveNorth() {
		y--;
		int temp = back;
		back = up;
		up = front;
		front = down;
		down = temp;

	}

	//남
	void moveSouth() {
		y++;
		int temp = back;
		back = down;
		down = front;
		front = up;
		up = temp;
	}

	//동
	void moveEast() {
		x++;
		int temp = back;
		back = right;
		right = front;
		front = left;
		left = temp;
	}

	//서
	void moveWest() {
		x--;
		int temp = back;
		back = left;
		left = front;
		front = right;
		right = temp;
	}

};

Dice dice;

void setField(int n, int m) {
	field = vector<vector<int>>(n, vector<int>(m, 0));
}

void input() {
	
	cin >> N >> M >> Y >> X >> C;
	setField(N, M);
	dice = Dice(Y, X);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> field[i][j];
		}
	}

	for (int i = 0; i < C; i++) {
		int k;
		cin >> k;
		orders.push_back(k);
	}
}


void solution() {
	for (auto iter : orders) {

		// 주사위가 이동할 수 없다면 무시
		if (!dice.canMove(iter))
			continue;

		//칸이 0이면 주사위의 아랫칸을 복사
		if (field[dice.getY()][dice.getX()] == 0) {
			field[dice.getY()][dice.getX()] = dice.getBack();
		}

		//주사위의 아래칸이 0일경우 칸에 있는 숫자를 주사위로 옮김
		else{
			dice.setBack(field[dice.getY()][dice.getX()]);
			field[dice.getY()][dice.getX()] = 0;
		}

		dice.move(iter);
		cout << dice.getFront() << "\n";
		
	}
}

int main() {
	input();
	solution();
}

//https://www.acmicpc.net/problem/14499