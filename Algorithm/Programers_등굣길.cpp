#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	vector<vector<int>> arr(n + 1, vector<int>(m + 1, 1));
	for (auto iter : puddles) {
		int y = iter[1];
		int x = iter[0];

		arr[y][x] = 0;

		if (y == 1) {
			for (int i = x; i <= m; i++) {
				arr[1][i] = 0;
			}
		}

		if (x == 1) {
			for (int i = y; i <= n; i++) {
				arr[i][1] = 0;
			}
		}
	}

	for (int y = 2; y <= n; y++) {
		for (int x = 2; x <= m; x++) {
			if (arr[y][x] == 0) continue;
			arr[y][x] = (arr[y - 1][x] + arr[y][x - 1]) % 1000000007;
		}
	}
	int answer = arr[n][m];
	return answer;
}