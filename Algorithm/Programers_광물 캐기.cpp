#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> map = { {"diamond",0},{"iron",1},{"stone",2} };

int table[3][3] = { {1,5,25}
		    ,{1,1,5}
		    ,{1,1,1} };


class Bundle {
public:
	Bundle(int _dia, int _iron, int _stone) {
		dia = _dia;
		iron = _iron;
		stone = _stone;
	}
	int getData(int data) {
		if (data == 0) return dia;
		else if (data == 1) return iron;
		else if (data == 2) return stone;
	}
private:
	int dia = 0;
	int iron = 0;
	int stone = 0;
};

vector<Bundle> arr;
int answer = 987654321;

int min(int a, int b) {
	return a > b ? b : a;
}

void dfs(vector<int> &picks, int cnt, int sum) {
	if (arr.size() == cnt) { answer = min(answer, sum); return; }
	if (sum > answer) return;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < picks[i]; j++) {
			picks[i]--;
			dfs(picks, cnt + 1, sum + arr[cnt].getData(i));
			picks[i]++;
		}
	}
}

int solution(vector<int> picks, vector<string> minerals) {
	int pickCnt = picks[0] + picks[1] + picks[2];
	int miningCnt = min(pickCnt * 5, minerals.size());
	int dia = 0, iron = 0, stone = 0, cnt = 0;
	for (int i = 0; i < miningCnt; i++) {
		dia += table[map[minerals[i]]][0];
		iron += table[map[minerals[i]]][1];
		stone += table[map[minerals[i]]][2];
		if (++cnt < 5 && (i != minerals.size() - 1)) continue;
		arr.push_back(Bundle(dia, iron, stone));
		cnt = 0, dia = 0, iron = 0, stone = 0;
	}
	dfs(picks, 0, 0);
	return answer;
}


int main(void) {
	vector<int> v1 = { 1, 3, 2 };
	vector<string> v2 = { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" };
	solution(v1, v2);
}
//https://school.programmers.co.kr/learn/courses/30/lessons/172927
