#include <string>
#include <vector>
#include <set>
#include <iostream>
//#include<bits/stdc++.h>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
	string answer(n, 'X');
	set<int> s;
	vector<int> erased;
	for (int i = 0; i < n; i++) {
		s.insert(i);
	}
	auto it = s.find(k);
	for (auto c : cmd) {
		if (c[0] == 'U') {
			int num = stoi(c.substr(2));
			while (num--) it--;
		}
		else if (c[0] == 'D') {
			int num = stoi(c.substr(2));
			while (num--) it++;
		}
		else if (c[0] == 'C') {
			erased.push_back(*it);
			it = s.erase(it);
			if (it == s.end()) it--;
		}
		else {
			s.insert(erased.back());
			erased.pop_back();
		}
	}
	for (auto x : s) answer[x] = 'O';
	return answer;

}
int main(void) {
	vector<string> s = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" };
	cout << solution(8, 2, s);
}
/*
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	stack<int> DelNums;
	vector<int> Table(n,1);
	int p = k;
	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i][0] == 'U') {
			int cnt = stoi(cmd[i].substr(2));
			while(cnt--){
				if(Table[p]){
					p--;
				}
				else {
					cnt++;
					p--;
				}

			}
		}
		else if (cmd[i][0] == 'D') {
			int cnt = stoi(cmd[i].substr(2));
			while(cnt--){
				if(Table[p]){
					p++;
				}
				else{
					cnt++;
					p++;
				}

			}
		}
		if (cmd[i][0] == 'C') {
			Table[p] = 0;
			DelNums.push(p);

			
			int end = n-1;
			while(!Table[end])
			{
				end--;
			}
			if(p == end)
			{
				while(!Table[p])
					p--;
			}
			else 
				p++;
			while(!Table[p])
			{
				p++;
			}
			
		}
		if (cmd[i][0] == 'Z') {
			Table[DelNums.top()] = 1;
			DelNums.pop();
		}
	}
	for (int i = 0; i < Table.size(); i++) {
		if (Table[i])
			answer += 'O';
		else
			answer += 'X';
	}
	return answer;
}
int main(void) {
	//vector<string> t1 = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" };
	//vector<string> t2 = {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"};
	vector<string> t2;
	t2.push_back("D 2");
	t2.push_back( "C");
	t2.push_back("U 3");
	t2.push_back("C");
	t2.push_back ("D 4");
	t2.push_back("C");
	t2.push_back("U 2");
	t2.push_back("Z");
	t2.push_back("Z");
	t2.push_back("Z");
	t2.push_back("U 1");
	t2.push_back("C");

	//cout << solution(8, 2, t1);
	cout << solution(8, 2, t2);
}
*/
//분석필요
