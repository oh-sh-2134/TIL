#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


bool cmp(pair<int, int>a, pair<int, int> b) {
	return a.first > b.first;
}

vector<int> solution(string s) {
	vector<int> answer;
	unordered_map<string, int>m;
	vector<pair<int, int>> temp;
	string nums = "";
	for (auto num : s) {
		
		if (num >= '0' && num <= '9') {
			nums.push_back(num);
			continue;
		}
		if (nums.size() > 0) {
			m[nums]++;
			nums.clear();
		}
		
	}
	for (auto nums : m) 
		temp.push_back({ nums.second, stoi(nums.first) });
	sort(temp.begin(), temp.end(), cmp);
	for (auto num : temp)
		answer.push_back(num.second);
	return answer;
}

int main(void) {
	string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
	s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
	solution(s);
}