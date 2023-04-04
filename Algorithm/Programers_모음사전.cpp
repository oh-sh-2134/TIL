#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(string word) {
	int answer = 0;
	unordered_map<char, int> m;
	vector<int> alpaGap = { 781,156,31,6,1 };
	m['A'] = 0;
	m['E'] = 1;
	m['I'] = 2;
	m['O'] = 3;
	m['U'] = 4;
	for (int i = 0; i < word.size(); i++)
		answer += 1 + m[word[i]] * alpaGap[i];

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/84512