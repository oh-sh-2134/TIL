#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> m;
	for (auto iter : participant) {
		if (m.find(iter) != m.end()) m[iter] += 1;
		m.insert({ iter,1 });
	}

	for (auto iter : completion) {
		if (m[iter])
			m[iter] -= 1;
	}

	for (auto iter : m) {
		if (iter.second)
			answer = iter.first;
	}
	return answer;
}