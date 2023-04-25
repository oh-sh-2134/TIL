#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	int i = 0;
	while (i < arr.size()) {
		if (answer.empty()) { answer.push_back(arr[i]); }
		else if (answer[answer.size() - 1] == arr[i]) answer.pop_back();
		else if (answer[answer.size() - 1] != arr[i]) answer.push_back(arr[i]);
		i++;
	}
	if (answer.size() == 0) answer.push_back(-1);
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/181859

int main(void) {
	vector<int> v = { 0, 1, 1, 1, 0 };
	solution(v);
}