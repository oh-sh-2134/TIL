#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer;
	unordered_map<string, int> playerNameMap;
	unordered_map<int, string> playerPosMap;
	for (int i = 0; i < players.size(); i++) playerNameMap[players[i]] = i;
	for (int i = 0; i < players.size(); i++) playerPosMap[i] = players[i];
	for (auto name : callings) {
		if (playerNameMap[name] == 0) continue;
		int cur = playerNameMap[name];
		int pre = cur - 1;

		string curname = playerPosMap[cur];
		string prename = playerPosMap[pre];

		playerPosMap[pre] = curname;
		playerPosMap[cur] = prename;

		playerNameMap[curname] = pre;
		playerNameMap[prename] = cur;
	}
	for (int i = 0; i < players.size(); i++) answer.push_back(playerPosMap[i]);
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/178871