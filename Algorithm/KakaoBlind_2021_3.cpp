#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

string l[4][4] = { {"-", "cpp", "java", "python"},
				  {"-", "backend", "frontend"},
				  {"-", "junior", "senior"},
				  {"-", "chicken", "pizza"} };
		// -는 해당 카테고리의 모든 조건에 해당함
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	vector<vector<int>> dir(108);
	//dir(108)은 query에서 특정 조건에 대한 경우의 수를 모두 저장하기 위함 4*3*3*3
	for (auto s : info)
	{
		int idx1 = 0;
		int idx2 = s.find(" ", idx1);
		int v[4];
		for (int i = 0; i < 4; i++)
		{
			string extraction = s.substr(idx1, idx2 - idx1);
			idx1 = idx2 + 1;
			idx2 = s.find(" ", idx1);
			v[i] = find(l[i], l[i] + 4, extraction) - l[i];
		}
		//데이터 파싱하여 저장
		
		int score = stoi(s.substr(idx1, 10));
		for (int c1 : {0, v[0]})
		{
			for (int c2 : {0, v[1]})
			{
				for (int c3 : {0, v[2]})
				{
					for (int c4 : {0, v[3]})
					{
						int idx = c1 * 27 + c2 * 9 + c3 * 3 + c4;
						dir[idx].push_back(score);
					}
				}
			}
		}
		// -에 해당하는 케이스때문에 해당 카테고리의 조건이 있을떄와 없을때 , 두가지 경우에 해당하는 배열에 scroe을 저장
	}

	for (int i = 0; i < 108; i++)
		sort(dir[i].begin(), dir[i].end());
	//lower_bound를 사용하기 위해 미리 정렬
	for (auto q : query)
	{
		int idx1 = 0;
		int idx2 = q.find(" ", idx1);
		int v[4];
		for (int i = 0; i < 4; i++)
		{
			string extraction = q.substr(idx1, idx2 - idx1);
			idx1 = idx2 + 5;
			idx2 = q.find(" ", idx1);
			v[i] = find(l[i], l[i] + 4, extraction) - l[i];
		}
		int score = stoi(q.substr(idx1-4, 10));
		int idx = v[0] * 27 + v[1] * 9 + v[2] * 3 + v[3];
		answer.push_back(dir[idx].end() - lower_bound(dir[idx].begin(), dir[idx].end(), score));
		//query score보다 큰 수를 구하는 것은 해당 배열에서 score보다 작은 숫자가 첫번째로 나타나는 공간의 인덱스를 맨 마지막 인덱스에서 빼면 됨
	}
	return answer;
}

int main(void)
{
	vector<string> v2 = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
	vector<string> v1 = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };

	for (auto ele : solution(v1, v2))
	{
		cout<< ele;
	}
}

//https://github.com/encrypted-def/kakao-blind-recruitment/blob/master/2021-blind/Q3_1.cpp  참고
//c++을 어느정도 아는것 같은데도 새로운것들이 많다 
//lower_bound ,uper_bound 그리고 for(auto c1 : {0,v[1]})에서 0과 v[1]을 차례로 넣음 : c++ 11에 추가된 문법 하나 알아감
