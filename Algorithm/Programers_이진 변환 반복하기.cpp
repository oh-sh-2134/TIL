#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string convertBinary(int n) {
	string temp = "";
	while (n != 0) {
		temp.append(to_string((int)n & 1));
		n = n >> 1;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
vector<int> solution(string s) {
	vector<int> answer;
	int zeroCnt = 0;
	int convertCnt = 0;
	string convertResult = "";
	while (convertResult != "1") {
		int size = s.size();
		convertResult = "";
		// 0제거
		for (auto&e : s) {
			if (e == '1')
				convertResult += "1";
		}
		// 제거된 0 카운트
		zeroCnt += size - convertResult.size();

		// 2진 변환
		convertResult = convertBinary(conve rtResult.size());
		s = convertResult;
		convertCnt++;
	}
	answer = { convertCnt, zeroCnt };
	return answer;
}