#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> m;
	for (auto iter : clothes)
		m[iter[1]]++;

	for (auto iter : m)
		answer *= (iter.second + 1);
	return answer - 1;
}