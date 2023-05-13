#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> prfitTable;
unordered_map<string, string> enrollTable;

void distribute(string seller, int money) {
	if (seller == "-") return;
	int part = money * 0.1;
	prfitTable[seller] += money - part;
	if (part) distribute(enrollTable[seller], part);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;
	for (int i = 0; i < enroll.size(); i++)
		enrollTable[enroll[i]] = referral[i];


	for (int i = 0; i < seller.size(); i++)
		distribute(seller[i], amount[i] * 100);

	for (int i = 0; i < enroll.size(); i++)
		answer.push_back(prfitTable[enroll[i]]);

	return answer;
}

int main(void) {
	vector<string> e = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
	vector<string> r = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
	vector<string> s = { "young", "john", "tod", "emily", "mary" };
	vector<int> a = { 12, 4, 2, 5, 10 };
	solution(e, r, s, a);
}
//https://school.programmers.co.kr/learn/courses/30/lessons/77486