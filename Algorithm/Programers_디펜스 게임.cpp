#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
	if (enemy.size() <= k) return enemy.size();
	priority_queue<int> mujak;

	for (int i = 0; i < enemy.size(); i++) {
		//k까지는 방어를 보장함
		if (i < k) {
			mujak.push(-1 * enemy[i]); 
			continue;
		}
		mujak.push(-1 * enemy[i]);
		int lower = -mujak.top();
		mujak.pop();
		n -= lower;
		if (n < 0) return i;
	}
	return enemy.size();
}
//https://school.programmers.co.kr/learn/courses/30/lessons/142085#