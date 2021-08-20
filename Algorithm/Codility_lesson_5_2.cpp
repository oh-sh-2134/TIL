#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
	// write your code in C++14 (g++ 6.2.0)
	vector<pair<int, int>>stoi;
	int cnt = 0;
	vector<int>sol;
	for (auto element : S)
	{
		if (element == 'A')
			stoi.push_back(make_pair(1, cnt));
		else if (element == 'C')
			stoi.push_back(make_pair(2, cnt));
		else if (element == 'G')
			stoi.push_back(make_pair(3, cnt));
		else if (element == 'T')
			stoi.push_back(make_pair(4, cnt));
		cnt++;
	}
	sort(stoi.begin(), stoi.end());
	for (int i = 0; i < P.size(); i++)
	{
		for (int j = 0; j < stoi.size(); j++)
		{
			if (P[i] <= stoi[j].second && Q[i] >= stoi[j].second)
			{
				sol.push_back(stoi[j].first);
				break;
			}
		}

	}
	return sol;
}


int main(void)
{
	string s = "CAGCCTA";
	vector<int>P = { 2,5,0 };
	vector<int>Q = { 4,5,6 };

	vector<int>sol(solution(s, P, Q));
	for (auto it : sol)
	{
		cout << it << " ";
	}
}

// https://app.codility.com/demo/results/training4USY2U-V4V/
// 첫번쨰 아이디어 실패
// https://app.codility.com/demo/results/training4JSYXF-6BG/
// 두번째 성공