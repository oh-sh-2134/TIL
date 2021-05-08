#include <string>
#include <vector>
#include <iostream>

using namespace std;

int abs(int n) {
	return n >= 0 ? n : n * (-1);
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	vector<pair<int, int>> p;
	char arr[5][5];
	for (int t = 0; t < 5; t++) {
		bool flag = false;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				arr[i][j] = places[t][i][j];
			}
		}
		p.clear();
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (arr[i][j] == 'P') {
					p.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < p.size(); i++) {
			if (flag) break;
			for (int j = i+1; j < p.size(); j++) {
				int x1, x2, y1, y2, xdist, ydist, dist;
				y1 = p[i].first;
				x1 = p[i].second;
				y2 = p[j].first;
				x2 = p[j].second;
				ydist = abs(y1 - y2);
				xdist = abs(x1 - x2);
				dist = ydist + xdist;

				if (dist == 1) {
					flag = true;
					break;
				}
				else if (dist == 2) {
		
					if (x1 == x2) {
						if (arr[(y1 + y2) / 2][x1] != 'X') {
							flag = true;
							break;
						}
					}
					else if (y1 == y2) {
						if (arr[y1][(x1 + x2) / 2] != 'X') {
							flag = true;
							break;
						}
					}
					else if (arr[y1][x2] != 'X') {
						//if (arr[y1][x2] != 'X' && arr[y2][x1] != 'X') {
						flag = true;
						break;
						//}
					}
					else if (arr[y2][x1] != 'X') {
						flag = true;
						break;
					}
				}
			}
		}
		answer.push_back(!flag);
	}

	return answer;
}


int main(void) {
	vector<vector<string>> v = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
	vector<int> s;
	s = solution(v);
	for (int i = 0; i < s.size(); i++) {
		cout << s[i]<<"\n";
	}
}