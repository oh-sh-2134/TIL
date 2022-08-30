#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	for (auto iter : arr) {
		if (answer.size() == 0) answer.push_back(iter);
		if (answer.back() == iter) continue;
		answer.push_back(iter);
	}


	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12906