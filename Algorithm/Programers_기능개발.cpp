#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int>v1(progresses);
	vector<int> v2(speeds);
	vector<int> answer;
	int cnt = 0;
	int pos = 0;
	while (pos != v1.size()) {
		if (v1[pos] >= 100) {
			while (v1[pos] >= 100) {
				pos += 1;
				cnt++;
				if (pos == v1.size()) break;
			}
			answer.push_back(cnt);
			cnt = 0;

		}
		for (int i = pos; i < v1.size(); i++) {
			if (v1[i] < 100)
				v1[i] += v2[i];
		}
	}
	return answer;
}