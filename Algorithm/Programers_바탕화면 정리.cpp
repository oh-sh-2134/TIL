#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;
	int minX = 50;
	int maxX = 0;
	int minY = 50;
	int maxY = 0;
	for (int i = 0; i < wallpaper.size(); i++) {
		for (int j = 0; j < wallpaper[i].size(); j++) {
			if (wallpaper[i][j] != '#') continue;
			if (i < minX) minX = i;
			if (i > maxX) maxX = i;
			if (j < minY) minY = j;
			if (j > maxY) maxY = j;

		}
	}
	answer.push_back(minX);
	answer.push_back(minY);
	answer.push_back(maxX + 1);
	answer.push_back(maxY + 1);
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/161990?language=cpp