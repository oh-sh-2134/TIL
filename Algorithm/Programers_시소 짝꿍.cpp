#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

long long ratio[3][2] = { {2,1}, {4,3}, {3,2} };

long long solution(vector<int> weights) {
	int idx = 0;
	long long answer = 0;
	set<int> weightSet;
	unordered_map<int, int> weightCnt;

	for (auto weight : weights)
	{
		weightSet.insert(weight);
		weightCnt[weight]++;
	}

	for (auto weight : weightSet)
	{
		long long weightSize = weightCnt[weight];
		answer += (weightSize * (weightSize - 1)) / 2;

		for (int i = 0; i < 3; i++)
		{
			if (weight % ratio[i][1])
				continue;

			long long size = weightCnt[(weight / ratio[i][1]) * ratio[i][0]];
			answer += weightSize * size;
		}
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/152996