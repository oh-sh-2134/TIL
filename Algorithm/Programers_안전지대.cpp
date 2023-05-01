#include <string>
#include <vector>

using namespace std;
enum {
	NONE = 0,
	BOOM = 1,
	DANGER = 2
};
int dy[8] = { 0,0,1,-1,1,1,-1,-1 };
int dx[8] = { 1,-1,0,0,1,-1,-1,1 };

int solution(vector<vector<int>> board) {
	int answer = board.size()*board[0].size();
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] != BOOM) continue;
			answer--;
			for (int d = 0; d < 8; d++) {
				int y = i + dy[d];
				int x = j + dx[d];
				if (y < 0 || y >= board.size() || x < 0 || x >= board[i].size()) continue;
				if (board[y][x] != NONE) continue;
				board[y][x] = DANGER;
				answer--;
			}
		}
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/120866