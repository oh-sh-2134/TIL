#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer;
	unordered_map<char, int> key;
	for (auto iter : keymap) {
		for (int i = 0; i < iter.size(); i++) {
			if (key.find(iter[i]) == key.end()) {
				key[iter[i]] = i + 1;
				continue;
			}
			if (key[iter[i]] > i + 1)
				key[iter[i]] = i + 1;
		}
	}
	for (auto iter : targets) {
		int keyCnt = 0;
		for (int i = 0; i < iter.size(); i++) {
			if (key.find(iter[i]) == key.end()) {
				keyCnt = -1;
				break;
			}
			keyCnt += key[iter[i]];
		}
		answer.push_back(keyCnt);
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/160586