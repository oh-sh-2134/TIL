#include<iostream>
#include <string>
#include <vector>
#define MAX 10
using namespace std;

//����ġ�� �ִ� ���ھ ��ȯ�ϴ� �Լ�
int check_Score(vector<int> v) {
	int score = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i])
			score += MAX - i;
	}
	return score;
}

//���ھ��� �� �Լ�
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
	//�ִ� ���� ���� ����ϱ� ���� ���� �ʿ� + ������ answer�� ����
	vector<int> answer;
	int maxAnswer = 0;

	//��Ʈ ����ŷ ������ 1�� ���̾��� �̱� 0�� ����ġ�� �̱�

	//����ġ�� �ִ� ���ھ ���� �����ص�
	int maxScore = check_Score(info);

	//for���� 1<<11 ��ŭ ���ƾ���
	for (int c = 0; c < (1 << 11); c++) {
		//���µǾ���ϴ� �� : ���̾��� �� �� �ִ� ȭ��߼�, ���� ���̾��� ���ھ�� ����ġ�� ���ھ�,
		//                  ���̾��� ������
		int rn = n;
		int r_score = 0, a_score = maxScore;
		vector<int> rBorad(11, 0);

		// for�� 10~0���� ���ƾ���, �̱�� ���� ���� �ٷ� �ǳʶ�(��Ʈ��ŷ?) 
		//+ for���� �� �������ϰ� break�ϰ�� �Ұ����� ����� ����
		int cnt = 11;
		for (int i = 10; i >= 0; i--) {
			cnt--;
			//0�� ���̾��� ������ 
			if ((c&(1 << i)) == 0) continue;

			//�̱游ŭ�� ȭ���� ���Ҵ��� Ȯ�� -> ȭ���� ���µ� �̰ܾ��Ѵٸ� break;
			if (rn - (info[MAX - i] + 1) < 0) break;

			//rn�� ���� ����ġ�� ���� �߼����� ���ƾ��� �ƴϸ� ���̱�� ����� breakó��
			if (info[MAX - i] > rn) break;

			
			//�̱� �� ���� ��� �ش� ���ھ�� ȭ�� �Ҹ� + ����ġ�� ���̾� ���ھ� ���� + ���̾� ���ھ�� ����
			rn -= (info[MAX - i] + 1);
			r_score += i;
			if (info[MAX - i])
				a_score -= i;
			rBorad[MAX - i] = info[MAX - i] + 1;
		}
		// �߻��� �� ���� ����� ��(for���� �� ���� ���� == �̰ܾ��ϴ� ���̽����� �̱� �� ����)
		if (cnt != 0) continue;

		//���̾��� ���ų� �����϶��� �н� ��
		if (a_score >= r_score) continue;

		//ȭ���� ������ ������ ���� 0���� �߻�
		if (rn > 0)
			rBorad[MAX] = rn;

		//���� ����϶��� ���ھ��� �񱳰� �ʿ���
		if (maxAnswer == r_score - a_score) {
			answer = cmp(answer, rBorad);
			continue;
		}

		//�ִ� ������ �ƴ� ��� �н�
		if (maxAnswer > (r_score - a_score)) continue;

		//�ּ��϶� ������ ����
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