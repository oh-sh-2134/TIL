#include<iostream>
#include <string>
#include <vector>
#define MAX 10
using namespace std;

//어피치의 최대 스코어를 반환하는 함수
int check_Score(vector<int> v) {
	int score = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i])
			score += MAX - i;
	}
	return score;
}

//스코어판 비교 함수
vector<int> cmp(vector<int> answer, vector<int> rBorad) {
	for (int i = 0; i <= MAX; i++) {
		if (answer[MAX - i] < rBorad[MAX - i])
			return rBorad;
		if (answer[MAX - i] > rBorad[MAX - i])
			return answer;
	}
	return answer;
}

vector<int> solution(int n, vector<int> info) {
	//최대 점수 차를 기록하기 위한 변수 필요 + 정답을 answer로 관리
	vector<int> answer;
	int maxAnswer = 0;

	//비트 마스킹 쓸꺼임 1이 라이언이 이김 0은 어피치가 이김

	//어피치의 최대 스코어를 먼저 저장해둠
	int maxScore = check_Score(info);

	//for문을 1<<11 만큼 돌아야함
	for (int c = 0; c < (1 << 11); c++) {
		//리셋되어야하는 값 : 라이언이 쏠 수 있는 화살발수, 현재 라이언의 스코어와 어피치의 스코어,
		//                  라이언의 점수판
		int rn = n;
		int r_score = 0, a_score = maxScore;
		vector<int> rBorad(11, 0);

		// for문 10~0으로 돌아야함, 이길수 없는 경우는 바로 건너뜀(백트래킹?) 
		//+ for문을 다 돌지못하고 break일경우 불가능한 경우의 수임
		int cnt = 11;
		for (int i = 10; i >= 0; i--) {
			cnt--;
			//0은 라이언이 져야함 
			if ((c&(1 << i)) == 0) continue;

			//이길만큼의 화살이 남았는지 확인 -> 화살이 없는데 이겨야한다면 break;
			if (rn - (info[MAX - i] + 1) < 0) break;

			//rn이 현재 어피치가 맞춘 발수보다 많아야함 아니면 못이기는 경우임 break처리
			if (info[MAX - i] > rn) break;

			
			//이길 수 있을 경우 해당 스코어에서 화살 소모 + 어피치와 라이언 스코어 변경 + 라이언 스코어보드 변경
			rn -= (info[MAX - i] + 1);
			r_score += i;
			if (info[MAX - i])
				a_score -= i;
			rBorad[MAX - i] = info[MAX - i] + 1;
		}
		// 발생할 수 없는 경우의 수(for문을 다 돌지 못함 == 이겨야하는 케이스에서 이길 수 없음)
		if (cnt != 0) continue;

		//라이언이 졌거나 동점일때는 패스 함
		if (a_score >= r_score) continue;

		//화살이 남은게 있으면 전부 0에다 발사
		if (rn > 0)
			rBorad[MAX] = rn;

		//같은 경우일때는 스코어판 비교가 필요함
		if (maxAnswer == r_score - a_score) {
			answer = cmp(answer, rBorad);
			continue;
		}

		//최대 격차가 아닐 경우 패스
		if (maxAnswer > (r_score - a_score)) continue;

		//최소일때 데이터 갱신
		maxAnswer = r_score - a_score;
		answer = rBorad;

	}

	if (answer.size() == 0) answer.push_back(-1);
	return answer;
}
int main(void) {
	vector<int> s;

	int n = 5;
	vector<int> p = { 2,1,1,1,0,0,0,0,0,0,0 };
	//vector<int> p = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//vector<int> p = { 0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1 };
	//vector<int> p = { 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3 };
	
	s =solution(n,p);
	for (auto iter : s) {
		cout << iter << " ";
	}
	
}