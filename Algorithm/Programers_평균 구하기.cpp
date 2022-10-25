#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
	double answer = 0;
	for (auto e : arr) { answer += e; }
	return answer / arr.size();
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12944