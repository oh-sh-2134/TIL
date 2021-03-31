#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	long long result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case 'A':
		case 'B':
		case 'C':
			result += 3;
			break;
		case 'D':
		case 'E':
		case 'F':
			result += 4;
			break;
		case 'G':
		case 'H':
		case 'I':
			result += 5;
			break;
		case 'J':
		case 'K':
		case 'L':
			result += 6;
			break;
		case 'M':
		case 'N':
		case 'O':
			result += 7;
			break;
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			result += 8;
			break;
		case 'T':
		case 'U':
		case 'V':
			result += 9;
			break;
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			result += 10;
			break;
		}
	}
	cout << result << "\n";
	return 0;
}
//https://www.acmicpc.net/problem/5622
//알파벳마다 케이스별로 처리를 했음