#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_set>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<vector<bool>> visited;
vector<pair<int, int>> temp;
vector<int>oilMap = { 0 };


int bfs(vector<vector<int>> &land, int x, int y, int oilnum) {
	int oilCnt = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		land[cx][cy] = oilnum;
		temp.push_back({ cx,cy });
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx<0 || ny< 0 || nx >=land.size() || ny>=land[cx].size()) continue;
			if (land[nx][ny] == 0) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
		oilCnt++;
	}
	return oilCnt;
}


int max(int a, int b) {
	return a > b ? a : b;
}

int sicu(vector<vector<int>> &land) {
	int maxSicu = 0;
	int sicu = 0;
	unordered_set<int>oilIdx;
	for (int i = 0; i < land[0].size(); i++) {
		oilIdx.clear();
		sicu = 0;
		for (int j = 0; j < land.size(); j++) {
			if (land[j][i] == 0)	continue;
			oilIdx.insert(land[j][i]);
		}
		for (auto idx : oilIdx) {
			sicu += oilMap[idx];
		}
		maxSicu = max(maxSicu, sicu);		
	}
	return maxSicu;
}
int solution(vector<vector<int>> land) {
	int answer = 0;
	int oilNum = 0;
	visited = vector<vector<bool>>(land.size(), vector<bool>(land[0].size(), false));
	for (int i = 0; i < land.size(); i++) {
		for (int j = 0; j < land[i].size(); j++) {
			if (land[i][j] == 0) continue;
			if (visited[i][j]) continue;
			oilMap.push_back((bfs(land, i, j,++oilNum)));
		}
	}
	answer = sicu(land);
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/250136