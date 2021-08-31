#include <string>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;

map<string, int>frq[11];
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (auto order : orders)
	{
		sort(order.begin(), order.end());
		for (int i = 1; i < (1 << order.size()); i++)
		{
			string menu;
			int temp = i;
		
			for (int j = 0; j < order.size(); j++)
			{
				if (temp % 2) menu += order[j];
				temp /= 2;
			}
			frq[menu.size()][menu]++;
		}
	}

	for (auto i : course)
	{
		int maxfrq = 0;
		for (auto j : frq[i])
			maxfrq = max(maxfrq, j.second);
		if (maxfrq < 2) continue;
		for (auto j : frq[i])
		{
			if (j.second == maxfrq)
				answer.push_back(j.first);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}

//https://github.com/encrypted-def/kakao-blind-recruitment/blob/master/2021-blind/Q2.cpp#L10 참고
//경우의 수를 생각할때는 비트 마스크 이용하는 스킬 꼭 배워가기
