#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	//�̺�Ž���� ���� ����
	sort(times.begin(), times.end());
	//������ �ּҰ�
	long long start = 1;
	//������ �ִ�
	long long end = (long long)times[times.size() - 1] * n;
	long long mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		long long temp = 0;

		//�ش� �ð��ȿ� �ɻ縦 ���� �� �ִ� ����� �ּڰ��� ����
		for (auto iter : times)
			temp += (mid / iter);

		//����� �����ϴٸ� �ּڰ��� �÷�����
		if (temp < n) {
			start = mid + 1;
			continue;
		}
		//��������� �ּڰ��� ������ ��
		if (mid <= end)
			answer = mid;

		//����� ���´ٸ� �ִ��� �ٿ�����
		end = mid - 1;

	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/43238