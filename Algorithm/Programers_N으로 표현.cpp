#include <string>
#include <vector>
#define MAX 9

using namespace std;

int minDepth = MAX;
int tartget;
int source;

int  min(int a, int b) {
	return a > b ? b : a;
}

void dfs(int depth, int num) {
	if (depth >= MAX) {
		return;
	}

	if (num == tartget) {
		minDepth = min(depth, minDepth);
	}

	int operand = 0;
	for (int i = 1; i <= MAX; i++) {
		operand = operand * 10 + source;

		dfs(depth + i, num + operand);
		dfs(depth + i, num - operand);

		if (num != 0) {
			dfs(depth + i, num * operand);
			dfs(depth + i, num / operand);
		}
	}
}

int solution(int N, int number) {
	int answer = 0;
	tartget = number;
	source = N;
	dfs(0, 0);
	answer = ((minDepth >= MAX) ? -1 : minDepth);

	return answer;
}