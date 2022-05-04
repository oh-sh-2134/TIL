#include <string>
#include <vector>
#include <bitset>
#include <unordered_map>
using namespace std;

//	<보석명,<식별번호, 개수>>
unordered_map<string, pair<int, int>> gem;
bitset<100001> gemCheck;


int min(int a, int b) { return a > b ? b : a; }

vector<int> solution(vector<string> gems) {
	vector<int> answer(2);
	int num = 0;
	for (auto iter : gems) {
		if (gem.find(iter) == gem.end())
			gem.insert({ iter,{num++,0 } });
	}
	//setting
	for (int i = 0; i < gem.size(); i++) {
		gem[gems[i]] = { gem[gems[i]].first,gem[gems[i]].second + 1 };
		gemCheck[gem[gems[i]].first] = 1;
	}
	answer[0] = 1;
	answer[1] = gem.size();
	//바로 return 가능 케이스
	if (gemCheck.count() == gem.size()) return answer;

	string firstGem = gems[0];
	int minSize = gems.size();
	for (int i = gem.size(); i < gems.size(); i++) {


		//add gem
		gemCheck[gem[gems[i]].first] = 1;
		gem[gems[i]].second++;

		//check first gem
		while (gem[firstGem].second > 1) {
			answer[0]++;
			gem[firstGem].second--;
			firstGem = gems[answer[0] - 1];
		}

		if (gemCheck.count() == gem.size()) {

			if (minSize > i + 1 - answer[0]) {
				minSize = i + 1 - answer[0];
				answer[1] = i + 1;
			}

		}


	}
	return answer;
}