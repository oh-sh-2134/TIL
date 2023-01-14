#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
	int answer = 0;
	vector<int> round(elements);
	set<int> s;
	for (int i = 0; i < elements.size() - 1; i++)
		round.push_back(elements[i]);

	for (int i = 0; i < elements.size(); i++) {
		vector<int> v;
		for (int j = 0; j < elements.size(); j++) {
			int num = 0;
			for (int k = j; k < i + j + 1; k++)
				num += round[k];

			v.push_back(num);
		}
		for (int j = 0; j < v.size(); j++)
			s.insert(v[j]);
	}
	answer = s.size();
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/131701