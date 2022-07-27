#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	stack<int> stk;
	int package = 1;
	int pos = 0;
	while (package<order.size()+1) {
		if (package == order[pos]) {
			pos++;
			answer++;
		}
		else {
			stk.push(package);
		}
		while (stk.size() > 0 && order[pos] == stk.top()) {
			pos++;
			answer++;
			stk.pop();
		}
	
		package++;

	}
	return answer;
}