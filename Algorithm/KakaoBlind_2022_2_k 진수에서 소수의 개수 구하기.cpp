#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

bool isPrime(long long n) {
	if (n <= 1) {
		return false;
	}

	for (long long i = 2; i*i <= n; i++) {
		if ((n%i) == 0) {
			return false;
		}
	}

	return true;
}


string makeJinsu(int n, int k) {
	string s = "";
	while (n) {
		s += to_string(n%k);
		n /= k;
	}
	reverse(s.begin(), s.end());
	return s;
}

string convert0toSpace(string s) {
	for (long long i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			s[i] = ' ';
		}
	}
	return s;
}

int solution(int n, int k) {
	int answer = 0;
	long long token = 0;
	string s = convert0toSpace(makeJinsu(n, k));
	for (stringstream str(s); str >> token;) {
		if (isPrime(token))
			answer++;
	}
	return answer;
}