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
	//�ִ� ���� ����
	int minSize = gems.size();
	//���� ���� ī����
	for (auto iter : gems)
		gem[iter]++;
	kind = gem.size();
	gem.clear();
	while (true) {
		//start -> end������ ������ ������ ������ ������
		if (answer[1] == kind) break;

		//��� ������ ���� �Ǿ�������
		if (kind == gem.size()) {

			//start�� ��ġ�� �Űܺ�
			gem[gems[start]]--;
			if (gem[gems[start]] == 0) gem.erase(gem.find(gems[start]));
			start++;


			//���̰� �ּ��϶� �ֽ�ȭ
			if (minSize > end - start) {
				minSize = end - start;
				answer[0] = start;
				answer[1] = end;
			}
			continue;
		}
		//end�� ��ġ�� �Űܺ�
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