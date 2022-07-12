#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer = { 0,0 };

	int totalCnt = 1;
	int cnt = 0;
	char lastChar = ' ';
	unordered_set<string> s;

	for (auto iter : words) {

		//�����ձ� �ѻ���Ŭ ��������
		if (cnt == n) {
			cnt = 0;
			totalCnt++;
		}
		cnt++;

		//�̾� ���� ���ڰ� ������
		if (lastChar == ' ') {
			lastChar = iter[iter.size() - 1];
			s.insert(iter);
			continue;
		}

		//�ջ���� ������ ���ĺ��� �������� ���� ���
		if (lastChar != iter[0]) {
			answer.clear();
			break;
		}

		//���ߴ� ���� ���Ұ��
		if (s.find(iter) != s.end()) {
			answer.clear();
			break;
		}

		s.insert(iter);

		lastChar = iter[iter.size() - 1];

	}

	//������ �� ���� ��������
	if (answer.size() == 0) {
		answer.push_back(cnt);
		answer.push_back(totalCnt);
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12981