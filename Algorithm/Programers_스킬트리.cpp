#include <string>
#include <vector>
using namespace std;


vector<vector<int>> skill_board(26, vector<int>());
vector<bool> skill_pre(26, false);

bool checkPreSkill(int n) {
	for (auto iter : skill_board[n]) {
		if (!skill_pre[iter])
			return true;
	}
	return false;
}


int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 1; i < skill.size(); i++)
		//이전 스킬 정보를 담아둠
		skill_board[skill[i] - 'A'].push_back(skill[i - 1] - 'A');

	for (auto iter : skill_trees) {

		fill(skill_pre.begin(), skill_pre.end(), false);
		for (int i = 0; i < iter.size(); i++) {
			//이전 스킬을 배우지 않으면 break;
			if (checkPreSkill(iter[i] - 'A'))
				break;

			//배웠을때 로직
			skill_pre[iter[i] - 'A'] = true;

			//마지막까지 다 배울 수 있을 때
			if (i == iter.size() - 1) answer++;
		}
	}


	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/49993?language=cpp#