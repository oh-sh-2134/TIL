#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int findMax(vector<int>& v, int idx) {
	int temp = 0;
	for (int i = 0; i < 4; i++) {
		//중복은 제외
		if (i != idx)
			temp = max(temp, v[i]);
	}
	return temp;
}

int solution(vector<vector<int>> land)
{
	int answer = 0;
	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < 4; j++) {
			//해당 열에서의 최댓값
			land[i][j] += findMax(land[i - 1], j);
			answer = max(answer, land[i][j]);
		}
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12913