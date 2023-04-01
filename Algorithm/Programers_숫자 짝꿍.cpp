#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> mX;
unordered_map<char, int> mY;

string solution(string X, string Y) {
	string answer = "";
	auto min = [](int a, int b) {return a > b ? b : a; };
	for (int i = 0; i < X.size(); i++) mX[X[i]]++;
	for (int i = 0; i < Y.size(); i++) mY[Y[i]]++;

	for (int i = 9; i >= 0; i--) {
		int num = min(mX[i + '0'], mY[i + '0']);
		for (int j = 0; j < num; j++)
			answer += i + '0';
	}

	if (answer == "") return "-1";
	else if (answer[0] == '0') return "0";
	else return answer;
}