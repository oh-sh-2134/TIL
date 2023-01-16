#include <string>
#include <vector>
#include <algorithm>
#include <stack>
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


bool checkTree(string& str, int left, int right) {
	
	if (left == right) {
		return true;
	}
	int mid = (left + right) >> 1;
	if (str[mid] == '0') {
		for (int j = left; j <= right; j++) 
			if (str[j] == '1') return false;		
		return true;
	}
	return checkTree(str, left, mid - 1) & checkTree(str, mid + 1, right);
}

vector<int> solution(vector<long long> numbers) {
	vector<int> answer;
	for (auto n : numbers) {
		string strbit = makeTree(convertDec2Bin(n));
		answer.push_back(checkTree(strbit, 0, strbit.length() / 2));
	}
	return answer;
}

int main(void) {
	vector<long long> v = { 7, 42, 5 };
	solution(v);
}
//https://school.programmers.co.kr/learn/courses/30/lessons/150367
