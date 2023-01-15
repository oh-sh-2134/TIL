#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string convertDec2Bin(long long n) {
	string b = "";
	while (n) {
		if (n & 1)
			b += "1";
		else
			b += "0";
		n >>= 1;
	}
	reverse(b.begin(), b.end());
	return b;
}

string makeTree(string s) {
	long long k = 1;
	while (true) {
		if (s.size() <= k - 1)
			break;
		k <<= 1;
	}
	return string(k - 1 - s.length(), '0') + s;
}


bool checkNode(string s) {
	long long mid = (s.length()-1) / 2;
	if (s.size() == 3)
		return ((s[0] - '1') + (s[2] - '1')) <= (s[1] - '1') ? true : false;
	
	if (checkNode(s.substr(0, mid)) && checkNode(s.substr(mid + 1)))
		return s[mid] == '1';

	return false;
}

vector<int> solution(vector<long long> numbers) {
	vector<int> answer;
	for (auto n : numbers) {
		answer.push_back(checkNode(makeTree(convertDec2Bin(n))));
	}
	return answer;
}

int main(void) {
	//vector<long long> v = { 1610612735 };
	vector<long long> v = { 63, 111, 95 };
	solution(v);
}
