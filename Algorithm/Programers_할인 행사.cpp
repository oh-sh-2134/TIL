#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;

	unordered_map<string, int> require;
	for (int i = 0; i < want.size(); i++)
		require[want[i]] = number[i];

	for (int i = 0; i <= discount.size() - 10; i++) {
		unordered_map<string, int> result;

		for (int j = i; j < i + 10; j++) {
			result[discount[j]] += 1;
		}

		//unordered_map은 == oper가 먹힘
		if (result == require)
			answer++;
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/131127
