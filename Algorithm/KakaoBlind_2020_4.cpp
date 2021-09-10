#include <string>
#include <vector>
#include<iostream>


using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	for (auto q : queries)
	{
		int cnt = 0;
		for (auto w : words)
		{
			bool eql = true;
			if (q.length() > w.length())
				continue;
			for (int i = 0; i < w.length(); i++)
			{
				if (q[i] == '?')
					continue;
				else if (w[i] != q[i])
				{
					eql = false;
					break;
				}
			}
			if (eql)
				cnt++;
		}
		answer.push_back(cnt);
	}
	return answer;
}

int main(void) {
	vector<string> s1 = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
	vector<string> s2 = { "fro??", "????o", "fr???", "fro???", "pro?" };

	for (auto s : solution(s1, s2))
		cout << s;
}

//정확도만 긁었음
//복잡도는 추가공부...