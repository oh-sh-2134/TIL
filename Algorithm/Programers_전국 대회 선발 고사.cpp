#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
	vector<pair<int, int>> v;
	for (int i = 0; i < attendance.size(); i++)
		if (attendance[i]) v.push_back({ rank[i],i });
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.first < b.first;
	});
	int answer = v[0].second * 10000 + v[1].second * 100 + v[2].second;
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/181851