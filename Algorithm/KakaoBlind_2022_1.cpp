#include <string>
#include <vector>
#include <iostream>
#include<map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	map<string, int>list;

	map<string, vector<string>>rpt;
	for (auto l : id_list)
		list.insert({ l,0 });

	for (auto r : report)
	{
		int idx = r.find(" ", 0);
		string id1 = r.substr(0, idx);
		string id2 = r.substr(idx + 1, r.length() - idx);
		if (find(rpt[id2].begin(), rpt[id2].end(), id1) == rpt[id2].end())
			rpt[id2].push_back(id1);
	}
	for (auto l : list)
	{
		if (rpt[l.first].size() >= k)
		{
			for (auto r : rpt[l.first])
			{
				list[r] += 1;
			}
		}
	}
	vector<int> answer;
	for (auto id : id_list)
	{
		for (auto l : list)
		{
			if (id == l.first)
			{
				answer.push_back(l.second);
			}
		}
	}
	return answer;
}



int main(void)
{
	vector<string>s1 = { "muzi", "frodo", "apeach", "neo" };
	vector<string>s2 = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
	int k = 2;
	for (auto sol : solution(s1, s2, k))
	{
		cout << sol << " ";
	}
}