#include<iostream>
#include <string>
#include <vector>
#define MAX 1004
using namespace std;
int arr[MAX][MAX];

int max(int a, int b) {
	return a > b ? a : b;
}

int imos(vector<vector<int>> board, vector<vector<int>> skill) {
	//set damage
	for (auto index : skill) {
		//index[0] = type
		//index[1] = fy
		//index[2] = fx
		//index[3] = sy
		//index[4] = sx
		//index[5] = damage
		int type = 1;
		if (index[0] == 1)
			type *= (-1);

		arr[index[1]][index[2]] += index[5] * type;
		arr[index[3] + 1][index[4] + 1] += index[5] * type;
		arr[index[1]][index[4] + 1] -= index[5] * type;
		arr[index[3] + 1][index[2]] -= index[5] * type;

	}
	//damage 배열 계산
	for (int i = 1; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			arr[i][j] += arr[i - 1][j];
		}
	}
	for (int i = 0; i < board.size(); i++) {
		for (int j = 1; j < board[i].size(); j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}

	//기존 건물값에 damage 계산
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			arr[i][j] += board[i][j];
		}
	}

	//파괴된 건물 계산
	int cnt = 0;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (arr[i][j] > 1)
				cnt++;
		}
	}
	return cnt;


}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = imos(board, skill);
	return answer;
}

int main(void) {
	vector<vector<int>> v1 = { {1,2,3},{4,5,6},{7,8,9} };
	vector<vector<int>> v2 = { {1,1,1,2,2,4},{1,0,0,1,1,2},{2,2,0,2,0,100} };
	cout<<solution(v1, v2);
}
//https://imoz.jp/algorithms/imos_method.html