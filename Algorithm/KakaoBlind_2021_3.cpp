#include <string>
#include <vector>

using namespace std;

string l[4][4] = { {"-", "cpp", "java", "python"},
				  {"-", "backend", "frontend"},
				  {"-", "junior", "senior"},
				  {"-", "chicken", "pizza"} };
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	vector<vector<int>> L(108);
	for (auto s : info) {
		int v[4];
		int idx1 = 0, idx2 = s.find(" ", idx1);
		for (int i = 0; i < 4; i++) {
			string cond = s.substr(idx1, idx2 - idx1);
			idx1 = idx2 + 1;
			idx2 = s.find(" ", idx1);
			v[i] = find(l[i], l[i] + 4, cond) - l[i];
		}
		int score = stoi(s.substr(idx1, 10));
		for (int c1 : {0, v[0]}) {
			for (int c2 : {0, v[1]}) {
				for (int c3 : {0, v[2]}) {
					for (int c4 : {0, v[3]}) {
						int idx = c1 * 27 + c2 * 9 + c3 * 3 + c4;
						L[idx].push_back(score);
					}
				}
			}
		}
	}
	return answer;
}