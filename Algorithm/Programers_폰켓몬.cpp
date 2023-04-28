#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
	unordered_set<int> s;
	for (auto num : nums)
		s.insert(num);
	return nums.size() / 2 > s.size() ? s.size() : nums.size() / 2;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/1845