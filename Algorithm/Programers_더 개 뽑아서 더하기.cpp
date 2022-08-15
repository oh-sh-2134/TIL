#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	//set은 insert마다 sort 하기 때문에 마지막 vector에서 sort하기 위해 unordered_set사용
	unordered_set<int> us;
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			us.insert(numbers[i] + numbers[j]);
		}
	}
	answer.assign(us.begin(), us.end());
	sort(answer.begin(), answer.end());
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/68644