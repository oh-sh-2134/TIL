#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	int size = prices.size();
	vector<int> answer(size);
	stack<int> st;
	//position기반으로 처리
	for (int i = 0; i < size; i++) {
		//stack이 비었거나 가격이 떨어졌을때
		while (!st.empty() && prices[st.top()] > prices[i]) {
			//해당 position에 대한 처리
			answer[st.top()] = i - st.top();
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		answer[st.top()] = size - st.top() - 1;
		st.pop();
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/42584

