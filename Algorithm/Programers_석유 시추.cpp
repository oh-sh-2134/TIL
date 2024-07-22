#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
	int answer = 0;
	int additionalHealRequireCnt = bandage[0];
	int heal = bandage[1];
	int additionalHeal = bandage[2];
	int attackCnt = 0;
	int i = 0;
	int healCnt = 0;
	int currentHealth = health;
	while (attackCnt < attacks.size() && currentHealth > 0) {
		if (attacks[attackCnt][0] == i) {
			currentHealth  -= attacks[attackCnt][1];
			healCnt = 0;
			attackCnt++;
		}
		else {
			currentHealth = currentHealth + heal > health ? health : currentHealth + heal;
			healCnt++;
			if (healCnt == additionalHealRequireCnt) {
				currentHealth = currentHealth + additionalHeal > health ? health : currentHealth + additionalHeal;
				healCnt = 0;
			}
		}
		i++;
	}
	answer = currentHealth <= 0 ? -1 : currentHealth;
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/250137