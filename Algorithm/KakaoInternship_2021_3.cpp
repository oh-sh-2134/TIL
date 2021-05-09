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
			p -= (cmd[i][2] - '0');
			while (!Table[p]) {
				p -= 1;
			}
		}
		else if (cmd[i][0] == 'D') {
			p += (cmd[i][2] - '0');
			while (!Table[p]) {
				p += 1;
			}
		}
		if (cmd[i][0] == 'C') {
			Table[p] = 0;
			DelNums.push(p);
			bool flag = false;
			while (!Table[p] && p < Table.size()) {
				if (flag) {
					p -= 1;
				}
				else {
					p += 1;
					if (p == Table.size()) {
						p = DelNums.top();
						flag = true;
					}
				}
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
	vector<string> s = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" };
	cout << solution(8, 2, s);
}