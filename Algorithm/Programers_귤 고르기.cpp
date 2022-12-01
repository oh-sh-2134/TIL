#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	int sum = 0;
	unordered_map<int, int> m;
	vector<pair<int, int>> v;
	unordered_map<int, int>::iterator iter;
	for (auto iter : tangerine) m[iter]++;
	for (iter = m.begin(); iter != m.end(); iter++) v.push_back({ iter->first, iter->second });
	
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)->bool {
								return a.second > b.second; });	
	for (auto iter : v) {
		if (k < 1) break;
		answer++;
		//과일과 k를 곱해서 0이 될때는 한 종류의 과일을 다 고르거나 더 이상 고를 수 없을때
		while (iter.second*k) {
			k--;
			iter.second--;
		}
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/138476