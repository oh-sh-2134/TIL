#include<iostream>
#include<vector>
#include<queue>
using namespace std;


char arr[101][101];
int r, c;
int n;
vector<int> nums;

int mx[4] = { 0,0,-1,1 };
int my[4] = { 1,-1,0,0 };

void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		nums.push_back(k);
	}
}
//막대기 던지는 로직
void throwStick() {
	for (int i = 0; i < nums.size(); i++) {
		if (i % 2) {
			for (int j = 0; j < c; j++) {
				if (arr[nums[i]][j] == 'x') {
					arr[nums[i]][j] = '.';
					break;
				}
			}
		}
		else {
			for (int j = c - 1; j >= 0; j--) {
				if (arr[nums[i]][j] == 'x') {
					arr[nums[i]][j] = '.';
					break;
				}
			}
		}
	}
}

//땅에 붙은 미네랄처리
void setBase() {

}

//미네랄 아래로 내림
void move() {

}

void solution() {
	//막대기 던지기
	throwStick();
	bool flag = true;
	
	while (flag) {
		//땅에 붙은 미네랄을 방문처리

		//땅에 붙지 않은 미네랄들을 한칸찍 아래로 내림

	}
	
}

int main(void) {

}