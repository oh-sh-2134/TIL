#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Homework {
public:
	Homework(string _name, int _start, int _left) {
		name = _name;
		start = _start;
		left = _left;
	}
	string name = "";
	int start = 0;
	int left = 0;
};

int time2sec(string t) {
	if (t.size() < 5) return 0;
	return (stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2)));
}
vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;
	vector<Homework> arr;
	for (auto iter : plans) {
		arr.push_back(Homework(iter[0], time2sec(iter[1]), stoi(iter[2])));
	}
	sort(arr.begin(), arr.end(), [](Homework a, Homework b) {return a.start < b.start; });
	stack<int> stk;
	for (int i = 0; i < arr.size() - 1; i++) {
		int diff = arr[i + 1].start - arr[i].start;
		if (diff >= arr[i].left) {
			answer.push_back(arr[i].name);
			diff -= arr[i].left;
			arr[i].left = 0;
		}
		else {
			arr[i].left -= diff;
			diff = 0;
			stk.push(i);
		}
		while (diff > 0 && !stk.empty()) {
			if (arr[stk.top()].left > diff) {
				arr[stk.top()].left -= diff;
				diff = 0;
			}
			else {
				diff -= arr[stk.top()].left;
				arr[stk.top()].left = 0;
			}
			if (arr[stk.top()].left != 0) continue;
			answer.push_back(arr[stk.top()].name);
			stk.pop();
		}
	}
	answer.push_back(arr[arr.size() - 1].name);
	while (!stk.empty()) {
		answer.push_back(arr[stk.top()].name);
		stk.pop();
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/176962