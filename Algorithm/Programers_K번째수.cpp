#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (auto iter : commands) {
		int start = iter[0];
		int end = iter[1];
		int idx = iter[2];
		vector<int> temp;
		for (int i = start - 1; i < end; i++) {
			temp.push_back(array[i]);
		}
		sort(temp.begin(), temp.end());
		answer.push_back(temp[idx - 1]);
	}
	return answer;
}