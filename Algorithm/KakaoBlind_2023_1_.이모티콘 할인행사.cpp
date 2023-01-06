#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dcPercent[4] = { 40,30,20,10 };
int payMax;
int subMax;
int emoticonsCnt;
vector<int> g_emoticons;
vector<vector<int>> g_users;

vector<bool> visited;
vector<int>emoticonsDcInfo;
vector<int>userPayInfo;

void calculate() {

	userPayInfo.clear();
	userPayInfo.resize(g_users.size(), 0);

	//모든 이모티콘 순회
	for (int e = 0; e < g_emoticons.size(); e++) {
		//유저 순회
		for (int u = 0; u < g_users.size(); u++) {
			//퍼센트가 안맞다면 안삼
			if (dcPercent[emoticonsDcInfo[e]] < g_users[u][0]) continue;
			userPayInfo[u] += g_emoticons[e] - (g_emoticons[e] * dcPercent[emoticonsDcInfo[e]] / 100);
		}
	}

	int currentPay = 0;
	int currentSub = 0;
	for (int u = 0; u < g_users.size(); u++) {
		//결제금액이 기준을 넘어서면 구독해야함
		if (userPayInfo[u] >= g_users[u][1]) {
			currentSub++;
		}
		//넘지 못하면 지불 금액으로 처리
		else {
			currentPay += userPayInfo[u];
		}
	}
	if (subMax < currentSub) {
		subMax = currentSub;
		payMax = currentPay;
	}
	else if (subMax == currentSub) {
		if (payMax < currentPay) {
			payMax = currentPay;
		}
	}
}

void dfs(int current) {
	if (current == emoticonsCnt) {
		calculate();
		return;
	}
	for (int i = 0; i < 4; i++) {
		emoticonsDcInfo[current] = i;
		dfs(current + 1);
	}
	return;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;
	g_emoticons = emoticons;
	g_users = users;
	emoticonsCnt = emoticons.size();
	emoticonsDcInfo.resize(emoticonsCnt, 0);
	visited.resize(emoticonsCnt, false);
	//모든 이모티콘을 확인해야함
	dfs(0);
	answer = { subMax,payMax };
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/150368?language=cpp