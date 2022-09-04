#include <string>
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;

vector<vector<int>> dp;

int solution(int alp, int cop, vector<vector<int>> problems) {
	int answer = 0;
	int alp_MAX = alp, cop_MAX = cop; // 7, 10 테스트 케이스 핵심

	//problems에서 요구하는 최대 alp와 cop 체크
	for (auto &problem : problems) {
		if (problem[0] > alp_MAX)
			alp_MAX = problem[0];
		if (problem[1] > cop_MAX)
			cop_MAX = problem[1];
	}

	dp.resize(alp_MAX + 1, vector<int>(cop_MAX + 1, MAX));
	//처음 가진 alp와 cop 초기화
	dp[alp][cop] = 0;
	   
	for (int i = alp; i <= alp_MAX; i++) {
		for (int j = cop; j <= cop_MAX; j++) {
			if (i < alp_MAX) // 문제를 풀지 않고 alp를 1올릴때
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			if (j < cop_MAX) // 문제를 풀지 않고 cop를 1올릴때
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
			for (auto &problem : problems) {
				int alp_req = problem[0];
				int cop_req = problem[1];
				int alp_rwd = problem[2];
				int cop_rwd = problem[3];
				int cost = problem[4];
				int next_alp = i + alp_rwd;
				int next_cop = j + cop_rwd;
				if (i < alp_req || j < cop_req) continue; // 문제를 풀 수 없을때
				if (next_alp > alp_MAX || next_cop > cop_MAX) { // 최대 alp와 cop를 넘어서면 최대 alp, cop테이블에 저장
					next_alp = next_alp > alp_MAX ? alp_MAX : next_alp;
					next_cop = next_cop > cop_MAX ? cop_MAX : next_cop;
				}
				dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + cost); // 문제를 풀 수 있을때 갱신


			}
		}
	}
	answer = dp[alp_MAX][cop_MAX];
	return answer;
}

int main(void) {
	vector<vector<int>> p1 = { {10, 15, 2, 1, 2}, {20, 20, 3, 3, 4} };
	vector<vector<int>> p2 = { {0, 0, 2, 1, 2}, {4, 5, 3, 1, 2}, {4, 11, 4, 0, 2}, {10, 4, 0, 4, 2} };
	solution(0, 0, p2);
}

/* 
dfs 풀이
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;

vector<vector<int>> dp;
int n = 0, m = 0;
int dfs(int alp, int cop, vector<vector<int>> &problems) {
	//재귀 탈출 조건
	if (alp >= n && cop >= m) {
		return 0;
	}
	int &sol = dp[alp][cop];
	if (sol != -1) return sol; // 메모이제이션 체크
	sol = MAX;
	for (auto &problem : problems) {
		int alp_req = problem[0];
		int cop_req = problem[1];
		int alp_rwd = problem[2];
		int cop_rwd = problem[3];
		int cost = problem[4];
		if (alp < alp_req || cop < cop_req) continue;

		int nxt_alp = min(n, alp + alp_rwd);
		int nxt_cop = min(m, cop + cop_rwd);
		sol = min(sol, dfs(nxt_alp, nxt_cop, problems) + cost);

	}
	sol = min(sol, min(dfs(min(n, alp + 1), cop, problems) + 1, dfs(alp, min(m,cop + 1), problems) + 1));

	return sol;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
	int answer = 0;
	for (auto &problem : problems) {
		if (problem[0] > n)
			n = problem[0];
		if (problem[1] > m)
			m = problem[1];
	}

	dp.resize(151, vector<int>(151, -1));
	answer = dfs(alp, cop, problems);
	return answer;
}

*/