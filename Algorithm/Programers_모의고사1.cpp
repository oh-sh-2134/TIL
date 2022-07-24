#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(int a, int b) {
	return a > b;
}

vector<int> parse(string s) {
	vector<int> temp;
	for (int i = 0; i < s.size(); i++) {
		temp.push_back(s[i] - '0');
	}
	sort(temp.begin(), temp.end());
	return temp;
}

string solution(string X, string Y) {
	string answer = "";
	//x와 y를 정렬하여 비교한 후 공통 정수를 한곳에 담아 정렬하여 반환 계획
	vector<int> x = parse(X);
	vector<int> y = parse(Y);
	vector<int> sol;
	int xp = 0;
	int yp = 0;
	while (true) {
        if (xp == x.size() || yp == y.size()) break;
		if (x[xp] == y[yp]) {
			sol.push_back(x[xp]);
			xp++;
			yp++;
		}
		else if (x[xp] > y[yp]) {
			yp++;
		}
		else if (x[xp] < y[yp]) {
			xp++;
		}
	}
	if (!sol.empty()) {
		sort(sol.begin(), sol.end(),cmp);
		for (auto iter : sol) {
			answer += to_string(iter);
		}
		if (answer[0] == '0')
			answer = "0";
	}
	else {
		answer = "-1";
	}
	return answer;
}
