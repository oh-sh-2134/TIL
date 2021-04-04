#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	vector<string> croatian = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	int idx;
	string str;
	cin >> str;
	for (int i = 0; i < croatian.size(); i++)
	{
		while (1) {
			idx = str.find(croatian[i]); // 입력받은 문자열에서 croatian어가 있는지 체크 
			if (idx == string::npos) //더 이상 없으면 그만
				break;
			str.replace(idx, croatian[i].length(), "#"); //바꿀문자열이 있다면 교체
		}
	}
	cout << str.length();
}
//https://www.acmicpc.net/problem/2941
//replace 함수를 이용해서 크로아티안 문자열을 #으로 바꾸어서