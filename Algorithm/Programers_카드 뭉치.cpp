#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	string answer = "Yes";
	int p1 = 0, p2 = 0;
	for (auto iter : goal) {
		int total = p1 + p2;
		if (iter == cards1[p1])
			p1++;
		else if (iter == cards2[p2])
			p2++;
		if (total == p1 + p2) {
			answer = "No";
			break;
		}
	}
	return answer;
}