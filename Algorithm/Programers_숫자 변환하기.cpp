#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int x, int y, int n) {
	int answer = 0;
	unordered_set<int> cur;
	unordered_set<int> nxt;
	cur.insert(x);
	while (!cur.empty()) {
		if (cur.find(y) != cur.end()) return answer;
		for (auto iter : cur) {
			if (iter + n <= y)
				nxt.insert(iter + n);
			if (iter * 2 <= y)
				nxt.insert(iter * 2);
			if (iter * 3 <= y)
				nxt.insert(iter * 3);
		}
		cur = nxt;
		nxt.clear();
		answer++;
	}
	return -1;
}
int main(void) {
	solution(2, 5, 4);
}
//https://school.programmers.co.kr/learn/courses/30/lessons/154538