#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
	vector<int> answer = arr;
	for (int i = 0; i < query.size(); i++) {
		if (!(i & 1))
			answer.assign(answer.begin(), answer.begin() + query[i] + 1);
		else
			answer.assign(answer.begin() + query[i], answer.end());
		arr = answer;
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/181893

int main(void) {
	vector<int> arr = { 0, 1, 2, 3, 4, 5 };
	vector<int> q = { 4, 1, 2 };
	solution(arr, q);
}