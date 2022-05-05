#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> solution(vector<string> gems) {

	unordered_map<string, int> gem;
	vector<int> answer(2);
	int start = 0;
	int end = 0;
	int num = 0;
	int kind;
	//최대 쇼핑 개수
	int minSize = gems.size();
	//잼의 종류 카운팅
	for (auto iter : gems)
		gem[iter]++;
	kind = gem.size();
	gem.clear();
	while (true) {
		//start -> end까지의 개수가 보석의 종류와 같을때
		if (answer[1] == kind) break;

		//모든 보석이 포함 되어있을때
		if (kind == gem.size()) {

			//start의 위치를 옮겨봄
			gem[gems[start]]--;
			if (gem[gems[start]] == 0) gem.erase(gem.find(gems[start]));
			start++;


			//길이가 최소일때 최신화
			if (minSize > end - start) {
				minSize = end - start;
				answer[0] = start;
				answer[1] = end;
			}
			continue;
		}
		//end의 위치를 옮겨봄
		if (end < gems.size()) {
			gem[gems[end]]++;
			end++;
			continue;
		};
		break;
	}
	return answer;
}

int main(void) {
	vector<string>v = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
	v = { "A", "B", "B", "B", "B", "B", "B", "C", "B", "A" }; // [8, 10]
	v = { "A", "A", "A", "B", "B" }; // [3,4]
	solution(v);
}