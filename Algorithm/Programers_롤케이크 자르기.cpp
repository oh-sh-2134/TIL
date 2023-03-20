#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
	int answer = 0;
	map<int, int> chul;
	map<int, int> bro;

	for (auto iter : topping)
		bro[iter]++;

	for (int i = 0; i < topping.size() - 1; i++) {
		chul[topping[i]]++;
		bro[topping[i]]--;
		if (bro[topping[i]] == 0)
			bro.erase(topping[i]);
		if (chul.size() == bro.size())
			answer++;
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/132265