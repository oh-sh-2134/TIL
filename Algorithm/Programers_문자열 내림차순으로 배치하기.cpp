#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a > b;
}
string solution(string s) {
	vector<string> temp;
	string answer = "";
	for (int i = 0; i < s.length(); i++) {
		string k = "";
		k += s[i];
		temp.push_back(k);
	}
	sort(temp.begin(), temp.end(), cmp);
	for (auto iter : temp) {
		answer += iter;
	}
	return answer;
}