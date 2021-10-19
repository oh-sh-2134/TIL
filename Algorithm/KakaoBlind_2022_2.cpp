#include <string>
#include <vector>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

bool isPrime(long long n)
{
	if (n < 2)
		return false;
	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

string ntok(int a, int b)
{
	int mok = a, namerge = 0;
	int j = 0;
	int num = 0;

	vector<int>v;
	while (1)
	{
		if (mok == 0)
			break;
		namerge = mok % b;
		mok /= b;
		v.push_back(namerge);
	}
	string s;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		s += to_string(v[i]);
	}
	return s;
}

long long stolng(string s)
{
	long long l = 0;
	int j=0;
	for (int i = s.length()-1; i >= 0; i--)
	{
		l += (s[i]-'0')*pow(10, j);
		j++;
	}

	return l;
}

int solution(int n, int k) {
	int answer = -1;
	int cnt = 0;
	string s = ntok(n, k);
	int idx1 = 0;
	int idx2 = s.find("0", idx1);
	if (idx2 == -1)
	{
		if (isPrime(stolng(s)))
			return 1;
	}
	while(1)
	{
		if (idx1 == s.length()+1)
			break;

		int num = stolng(s.substr(idx1, idx2 - idx1));
		if (isPrime(num))
			cnt++;
		idx1 = idx2 + 1;
		idx2 = s.find("0", idx1);
		if (idx2 == -1)
		{
			idx2 = s.length();
		}
	}
	
	answer = cnt;

	return answer;
}


int main(void)
{
	int n = 437674;
	int k = 3;
	cout << solution(n, k);
}