#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
	int packageCnt = 0;
	stack<int> sub;
	for (int i = 1; i <= order.size(); i++) {
		sub.push(i);
		while (!sub.empty()) {
			if (sub.top() != order[packageCnt])
				break;
			sub.pop();
			packageCnt++;
		}
	}
	return packageCnt;
}


int main(void) {
	vector<int> v = { 3, 5, 4, 2, 1 };
	solution(v);
}
//https://school.programmers.co.kr/learn/courses/30/lessons/131704