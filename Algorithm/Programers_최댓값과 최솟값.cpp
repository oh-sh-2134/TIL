#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer = "", token = "";
	vector<int> v;

	for (stringstream str(s); str >> token;)
		v.push_back(stoi(token));
	sort(v.begin(), v.end());

	answer += to_string(v.front()) + ' ' + to_string(v.back());
	return answer;
}