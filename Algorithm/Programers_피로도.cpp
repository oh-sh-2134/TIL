#include <string>
#include <vector>

using namespace std;
vector<vector<int>> staticDungeons;
bool visited[8];
int maxIdx;
void dfs(int currentPirodo, int sequence) {
	for (int i = 0; i < staticDungeons.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		if (currentPirodo >= staticDungeons[i][0] && currentPirodo - staticDungeons[i][1] >= 0)
			dfs(currentPirodo - staticDungeons[i][1], sequence + 1);
		visited[i] = false;
	}
	if (sequence > maxIdx)
		maxIdx = sequence;

}

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;
	staticDungeons = dungeons;
	dfs(k, 0);
	if (maxIdx > 0)
		answer = maxIdx;
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/87946