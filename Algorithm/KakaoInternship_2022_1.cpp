#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, int> m;
string solution(vector<string> survey, vector<int> choices) {
	//vector<pair<string, string>> board = { {"R" , "T"}, {"C", "F"}, {"J","M"},{"A","N"} };
	vector<pair<char, char>> board;
	board.push_back({ 'R' , 'T' });
	board.push_back({ 'C', 'F' });
	board.push_back({ 'J','M' });
	board.push_back({ 'A','N' });

	for (auto pair : board) {
		m[pair.first] = 0;
		m[pair.second] = 0;
	}
	for (int i = 0; i < choices.size(); i++) {
		if (choices[i] >= 4) {
			m[survey[i][1]] += (choices[i] - 4);
			continue;
		}
		m[survey[i][0]] += (4 - choices[i]);
	}
	string answer = "";
	for (auto result : board) {
		
	
		answer.push_back(m[result.first] >= m[result.second] ? result.first : result.second);
	}
	return answer;
}