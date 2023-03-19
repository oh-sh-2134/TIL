#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling)
{
	int answer = babbling.size();

	for (string s : babbling)
	{
		int babblingCase = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s.substr(i, 3) == "aya" && babblingCase != 1) { babblingCase = 1; i += 2; }
			else if (s.substr(i, 2) == "ma" && babblingCase != 2) { babblingCase = 2; i += 1; }
			else if (s.substr(i, 3) == "woo" & babblingCase != 3) { babblingCase = 3; i += 2; }
			else if (s.substr(i, 2) == "ye" && babblingCase != 4) { babblingCase = 4; i += 1; }
			else { answer--; break; }
		}
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/133499