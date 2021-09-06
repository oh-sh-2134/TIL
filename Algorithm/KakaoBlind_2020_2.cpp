#include <string>
#include <vector>
#include<stack>
#include<iostream>
using namespace std;

pair<bool,int> check(string str)
{
	stack<char> stk;
	int r = 0, l = 0,pos =0;

	bool correct = true;
	for (auto c : str)
	{
		pos++;
		if (c == '(')
		{
			stk.push(c);
			l++;
		}
		else
		{
			if (stk.empty())
			{
				correct = false;
				r++;
			}
			else
			{
				stk.pop();
				r++;
			}
		}
		if (r == l)
			return { correct,pos };

	}
}

string solution(string p) {
	if (!p.length())
		return p;
	pair<bool, int> correct;
	correct = check(p);

	string u = p.substr(0, correct.second);
	string v = p.substr(correct.second, p.length() - correct.second);

	if (correct.first)
		return u + solution(v);


	string answer = "(" + solution(v) + ")";
	if (!u.empty())
	{
		for (int i = 1; i < u.length() - 1; i++)
		{
			if (u[i] == '(')
				answer += ")";
			else
				answer += "(";
		}
	}
	return answer;
}

int main(void)
{
	string s = "()))((()";
	cout << solution(s);
}