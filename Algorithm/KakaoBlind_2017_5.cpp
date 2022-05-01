#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
	//문자열을 먼저 나눠야 함
	vector<string> divStr1;
	vector<string> divStr2;

	//대문자로 정렬하게
	int pos = 0;
	string s = "";
	for (int i = 1; i < str1.size(); i++) {
		if (!(((str1[i - 1] >= 'A' && str1[i - 1] <= 'Z') || (str1[i - 1] >= 'a' && str1[i - 1] <= 'z'))
			&& ((str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] >= 'a' && str1[i] <= 'z'))))
			continue;
		s = "";
		if (str1[i - 1] >= 'A' && str1[i - 1] <= 'Z')
			s += str1[i - 1];
		else if (str1[i - 1] >= 'a' && str1[i - 1] <= 'z')
			s += (str1[i-1] - 32);

		if (str1[i] >= 'A' && str1[i] <= 'Z')
			s += str1[i];
		else if (str1[i] >= 'a' && str1[i] <= 'z')
			s += (str1[i] - 32);

		divStr1.push_back(s);
	}

	for (int i = 1; i < str2.size(); i++) {
		if (!(((str2[i - 1] >= 'A' && str2[i - 1] <= 'Z') || (str2[i - 1] >= 'a' && str2[i - 1] <= 'z'))
			&& ((str2[i] >= 'A' && str2[i] <= 'Z') || (str2[i] >= 'a' && str2[i] <= 'z'))))
			continue;
		s = "";
		if (str2[i - 1] >= 'A' && str2[i - 1] <= 'Z')
			s += str2[i - 1];
		else if (str2[i - 1] >= 'a' && str2[i - 1] <= 'z')
			s += (str2[i - 1] - 32);

		if (str2[i] >= 'A' && str2[i] <= 'Z')
			s += str2[i];
		else if (str2[i] >= 'a' && str2[i] <= 'z')
			s += (str2[i] - 32);

		divStr2.push_back(s);
	}
	sort(divStr1.begin(), divStr1.end());
	sort(divStr2.begin(), divStr2.end());

	//교집합 구하기
	int intersectionCnt = 0;
	int i = 0, j = 0;
	while (i != divStr1.size() && j != divStr2.size()) {
		if (divStr1[i] == divStr2[j]) {
			intersectionCnt++;
			i++, j++;
		}
		else {
			if (divStr1[i] > divStr2[j]) {
				j++;
			}
			else
				i++;
		}
	}
	
	//합집합 구하기
	int unionCnt = divStr1.size()+divStr2.size() - intersectionCnt;
	
	if (intersectionCnt == 0 && unionCnt == 0) 
		return 65536;

	float cal = 0;
	cal = (float)intersectionCnt / unionCnt;
	int answer = cal * 65536;
	return answer;
}

int main(void) {
	string s1 = "handshake";
	string s2 = "shake hands";
	solution(s1, s2);
}