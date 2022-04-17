#include <string>
#include <vector>
using namespace std;

int arr[1001][1001];

vector<int> solution(int n) {
	vector<int> answer;
	int x = 0;
	int y = -1;
	int idx = 1;
	for (int i = n; i > 0; i--) {
		int cnt = i--;
		while(cnt--){
			y++;
			arr[y][x] = idx++;
		}
		if (i < 1) break;
		cnt = i--;
		while (cnt--) {
			x++;
			arr[y][x] = idx++;
		}
		if (i < 1) break;
		cnt = i;
		while (cnt--) {
			y--;
			x--;
			arr[y][x] = idx++;
		}
	
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) continue;
			answer.push_back(arr[i][j]);
		}
	}
	return answer;
}

int main(void) {
	solution(6);
}

//4[1, 2, 9, 3, 10, 8, 4, 5, 6, 7]
//5[1, 2, 12, 3, 13, 11, 4, 14, 15, 10, 5, 6, 7, 8, 9]
//6[1, 2, 15, 3, 16, 14, 4, 17, 21, 13, 5, 18, 19, 20, 12, 6, 7, 8, 9, 10, 11]
