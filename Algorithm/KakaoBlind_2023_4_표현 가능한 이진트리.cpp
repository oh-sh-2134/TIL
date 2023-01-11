#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string bitTree;
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
		if (s.size() <= k-1)
			break;
		k <<= 1;
	}
	return string(k - 1 - s.length(), '0') + s;
}


bool checkNode(string s) {
	long long mid = (s.length() - 1) / 2;
	if (s[mid] == '0')
		return false;
	if (s.size() == 3)
		return true;
	bool result = true;

	if (checkNode(s.substr(0, mid)))
		return checkNode(s.substr(mid+1, s.length()));
	return false;
}

vector<int> solution(vector<long long> numbers) {
	vector<int> answer;
	for (auto &n : numbers) {
		bitTree = makeTree(convertDec2Bin(n));
		answer.push_back(checkNode(makeTree(convertDec2Bin(n))));
	}
	return answer;
}

int main(void) {
	//vector<long long> v = { 1610612735 };
	vector<long long> v = { 63, 111, 95 };
	solution(v);
}