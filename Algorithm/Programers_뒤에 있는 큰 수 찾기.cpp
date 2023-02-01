#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer(numbers.size(), -1);
	stack<int> s;
	for (int i = 0; i < numbers.size(); i++) {
		int n = numbers[i];
		while (!s.empty() && numbers[s.top()] < n) {
			answer[s.top()] = n;
			s.pop();
		}
		s.push(i);
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/154539