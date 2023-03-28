#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> map = { {"diamond",0},{"iron",1},{"stone",2} };

int table[3][3] = { {1,1,1}
				,{5,1,1}
				,{25,5,1} };


class Bundle {
public :
	Bundle(int _dia, int _iron, int _stone) {
		dia = _dia;
		iron = _iron;
		stone = _stone;
	}
private:
	int dia = 0;
	int iron = 0;
	int stone = 0;
};

vector<Bundle> arr;

int min(int a, int b) {
	return a > b ? b : a;
}


int solution(vector<int> picks, vector<string> minerals) {
	int answer = 0;
	int miningCnt = min((picks[0] + picks[1] + picks[2])*5, minerals.size());
	int dia = 0, iron = 0, stone = 0, cnt = 0;
	for (int i = 0; i < miningCnt; i++) {
		dia += table[map[minerals[i]]][0];
		iron += table[map[minerals[i]]][1];
		stone += table[map[minerals[i]]][2];
		if (++cnt < 5) continue;
		arr.push_back(Bundle(dia,iron,stone));
		cnt = 0;
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/172927