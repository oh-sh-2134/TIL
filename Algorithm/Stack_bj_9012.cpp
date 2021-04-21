#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool vps(string ps) {
	stack<char> s;
	bool sw = true;
	for (int i = 0; i < ps.size(); ++i) {
		if (ps[i] == '(')
			s.push(ps[i]);
		else if (!s.empty() && ps[i] == ')')
			s.pop();
		else if (s.empty() && ps[i] == ')') {
			sw = false;
			break;
		}

	}
	if (s.empty() && sw) return true;
	else return false;
}
int main() {
	int num;
	string ps;
	cin >> num;
	for (int i = 0; i < num; ++i) {
		cin >> ps;
		if (vps(ps)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
//https://www.youtube.com/watch?v=krGrjpRzZBY
//스택을 응용해서 괄호가 맞는지 확인하면 됨
//괄호 )을 만나서 스택이 비어있으면 왼쪽 괄호가 없으니 NO