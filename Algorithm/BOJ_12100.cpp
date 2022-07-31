#include <iostream>
#include <queue>
#define MAX 20
using namespace std;

enum {
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3
};

int N;

int board[MAX][MAX];
int maxBlock;


void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}


void shiftLeft() {
	queue<int> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (board[i][j])
				q.push(board[i][j]);

			board[i][j] = 0;
		}

		int pos = 0;

		while (!q.empty()) {

			int data = q.front();
			q.pop();

			if (board[i][pos] == 0) {
				board[i][pos] = data;
			}

			else if (board[i][pos] == data) {
				board[i][pos] *= 2;
				pos++;
			}

			else {
				pos++;
				board[i][pos] = data;
			}

		}

	}
}

void shiftRight() {
	queue<int> q;
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j >= 0; j--) {
			if (board[i][j]) {
				q.push(board[i][j]);
			}

			board[i][j] = 0;
		}
		int pos = N - 1;

		while (!q.empty()) {
			int data = q.front();
			q.pop();

			if (board[i][pos] == 0) {
				board[i][pos] = data;
			}

			else if (board[i][pos] == data) {
				board[i][pos] *= 2;
				pos--;
			}

			else {
				pos--;
				board[i][pos] = data;
			}

		}

	}
}

void shiftUp() {
	queue<int> q;
	for (int i = 0; i < N;i++){
		for (int j = 0; j < N;j++){
			if (board[j][i])
				q.push(board[j][i]);

			board[j][i] = 0;
		}

		int pos = 0;
		while (!q.empty())
		{
			int data = q.front();
			q.pop();



			if (board[pos][i] == 0) {
				board[pos][i] = data;
			}

			else if (board[pos][i] == data){
				board[pos][i] *= 2;
				pos++;
			}

			else{
				pos++;
				board[pos][i] = data;
			}
		}
	}
}

void shiftDown() {
	queue<int> q;
	for (int i = 0; i < N;i++){
		for (int j = N - 1; j >=0; j--){
			if (board[j][i]) {
				q.push(board[j][i]);
			}

			board[j][i] = 0;
		}
		int pos = N - 1;

		while (!q.empty()){
			int data = q.front();
			q.pop();

			if (board[pos][i] == 0) {
				board[pos][i] = data;
			}

			else if (board[pos][i] == data){
				board[pos][i] *= 2;
				pos--;
			}

			else{
				pos--;
				board[pos][i] = data;
			}
		}
	}
}

void shift(int type){

	if (type == LEFT) {
		shiftLeft();
	}
	
	if (type == RIGHT) {
		shiftRight();
	}

	if (type == UP) {
		shiftUp();
	}

	if (type == DOWN) {
		shiftDown();
	}
}



void DFS(int cnt){

	if (cnt == 5){
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maxBlock = max(maxBlock, board[i][j]);
			}
		}
		return;
	}


	//현재 보드 상태 저장
	int currentBoard[MAX][MAX];	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			currentBoard[i][j] = board[i][j];
		}
	}



	for (int i = 0; i < 4; i++){
		shift(i);
		DFS(cnt + 1);			

		// 보드를 이전 상태로 되돌림
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				board[i][j] = currentBoard[i][j];
			}
		}

	}

}

void solution() {
	DFS(0);
	cout << maxBlock;
}


int main(void){
	input();
	solution();
	return 0;
}
//https://www.acmicpc.net/problem/12100