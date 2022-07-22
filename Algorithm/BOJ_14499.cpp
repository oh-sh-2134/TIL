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

//�ֻ����� ��� ������ ���ǵ� Ŭ����
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

	//�ֻ����� �̵��� �������� Ȯ��
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

	//��
	void moveNorth() {
		y--;
		int temp = back;
		back = up;
		up = front;
		front = down;
		down = temp;

	}

	//��
	void moveSouth() {
		y++;
		int temp = back;
		back = down;
		down = front;
		front = up;
		up = temp;
	}

	//��
	void moveEast() {
		x++;
		int temp = back;
		back = right;
		right = front;
		front = left;
		left = temp;
	}

	//��
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

		// �ֻ����� �̵��� �� ���ٸ� ����
		if (!dice.canMove(iter))
			continue;

		//ĭ�� 0�̸� �ֻ����� �Ʒ�ĭ�� ����
		if (field[dice.getY()][dice.getX()] == 0) {
			field[dice.getY()][dice.getX()] = dice.getBack();
		}

		//�ֻ����� �Ʒ�ĭ�� 0�ϰ�� ĭ�� �ִ� ���ڸ� �ֻ����� �ű�
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