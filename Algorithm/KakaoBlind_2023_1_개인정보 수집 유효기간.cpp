#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
using namespace std;

long long convertDay(string s) {
	vector<long long> v;
	long long num;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.')
			s[i] = ' ';
	}
	stringstream str(s);
	while (str >> num) {
		v.push_back(num);
	}
	return ((v[0] * 336) + (v[1] * 28) + (v[2]));
	//365 * 28
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;
	//convert today
	long long Today = convertDay(today);
	//convert tems
	unordered_map<char, long long> map;
	for (auto &term : terms) {
		long long num;
		char token;
		for (stringstream str(term); str >> token >> num;) {
			map[token] = (num * 28);
		}
	}
	//convert privacies
	int pos = 0;
	for (auto &privacie : privacies) {
		pos++;
		long long temp = convertDay(privacie);
		char trm = privacie.back();
		temp += map[trm];
		if (temp > Today) continue;
		answer.push_back(pos);

	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/150370