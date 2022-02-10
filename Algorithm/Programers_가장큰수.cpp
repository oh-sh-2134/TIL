#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> str;
	for (auto iter : numbers)
		str.push_back(to_string(iter));
	sort(str.begin(), str.end(), cmp);
	if (str[0] == "0") return "0";
	for (auto s : str)
		answer += s;
	return answer;
}