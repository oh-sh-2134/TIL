#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string s = "412";

string solution(int n) {
	string answer = "";
	while (n > 0) {
		answer += s[n % 3];
		n /= 3;
		if (answer[answer.size() - 1] == '4')
			n--;
	}
	reverse(answer.begin(), answer.end());
	return answer;
}
