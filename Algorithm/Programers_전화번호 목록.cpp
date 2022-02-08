#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	unordered_map<string, int> map;
	for (auto iter : phone_book)
		map[iter] = 1;
	for (int i = 0; i < phone_book.size(); i++) {
		string cmp = "";
		for (int j = 0; j < phone_book[i].size(); j++) {
			cmp += phone_book[i][j];
			if (map[cmp] && phone_book[i] != cmp)
				return false;
		}
	}
	return answer;
}