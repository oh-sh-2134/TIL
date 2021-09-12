#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	queue<pair<char, string>>q;
	map<string, string>m;
	for (auto s : record)
	{
		int idx1 = 0;
		int idx2 = s.find(" ", idx1);
		string cmd = s.substr(idx1, idx2 - idx1);
		string id;
		string subid;
		idx1 = idx2 + 1;
		idx2 = s.find(" ", idx1);
		id = s.substr(idx1, idx2 - idx1);
		if (cmd == "Leave") {
			q.push({ 'l',id });
			continue;
		}
		subid = s.substr(idx2 + 1, s.length() - idx2 - 1);
		if (cmd == "Enter")
		{
			if (m.find(id) == m.end())
				m.insert({ id,subid });
			if (m[id] != subid)
				m[id] = subid;
			q.push({ 'e', id });
		}
		else if (cmd == "Change")
		{
			m.at(id) = subid;
		}
	}
	while (!q.empty())
	{
		char cmd = q.front().first;
		string id = q.front().second;
		string s;
		if (cmd == 'e')
			s = m[id] + "님이 들어왔습니다.";
		else
			s = m[id] + "님이 나갔습니다.";
		q.pop();
		answer.push_back(s);
	}
	return answer;
}

int main(void)
{
	vector<string>v = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	for (auto e : solution(v))
	{
		cout << e << "\n";
	}
}

//https://www.welcomekakao.com/learn/courses/30/lessons/42888
//문자열 이용하는 문제 연습