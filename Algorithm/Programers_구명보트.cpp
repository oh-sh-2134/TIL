#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int together = 0;
	//같이 탈수 있었던 사람의 수와 people에 남은 수가 같으면 보트를 다 탄거임
	while (together < people.size()) {
		//같이 탈수 있으면(2명까지만 탈 수 있음)
		if (people[together] + people.back() <= limit) {
			together++;
		}
		people.pop_back();
		answer++;

	}


	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/42885