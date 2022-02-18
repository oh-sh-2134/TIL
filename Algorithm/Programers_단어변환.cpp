#include <string>
#include <vector>
#include <string.h>
using namespace std;
string s1;
string s2;
vector<string> strings;
bool visited[51];
int sol = 987654321;
int min(int a, int b) {
	return a > b ? b : a;
}
void dfs(string s, int n) {
	if (s == s2) {
		sol = min(n, sol);
		return;
	}

	int cnt = 0;
	for (int j = 0; j < strings.size(); j++) {
		if (visited[j]) continue;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != strings[j][i])
				cnt++;
		}
		if (cnt == 1) {
			visited[j] = true;
			dfs(strings[j], n + 1);
			visited[j] = false;
		}
		cnt = 0;
	}
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	s1 = begin;
	s2 = target;
	fill(visited, visited + words.size(), false);
	bool flag = false;
	for (auto iter : words) {
		if (iter == target) flag = true;
		strings.push_back(iter);
	}
	if (flag)
		dfs(begin, 0);
	if (sol != 987654321)
		answer = sol;
	return answer;
}