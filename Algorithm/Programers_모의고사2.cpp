#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

bool checkValid() {
	for (auto iter : m) {
		if (iter.second != 0) return false;
	}
	return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;
	for (int i = 0; i < want.size(); i++) {
		m.insert({ want[i],number[i] });
	}

	for (int i = 0; i < discount.size(); i++) {

		m[discount[i]]--;
		//10을 넘어갔을때
		if (i > 9) {
			if(m.find(discount[i - 10]) != m.end())
				m[discount[i - 10]]++;
		}

		//다 살수 있는 날
		if (checkValid())
			answer++;
	}


	return answer;
}