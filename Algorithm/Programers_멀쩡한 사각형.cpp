using namespace std;

long long gcd(int w, int h) {
	int k;
	while (h != 0) {
		k = w % h;
		w = h;
		h = k;
	}
	return w;
}

long long solution(int w, int h) {
	long long answer = (long long)w*h - (w + h) + gcd(w, h);
	return answer;
}
/*
�� ������ ������ �𸣰��� ��Ǭ�ٰ� ������
�߷��� �ִ� �簢������ ������ ���� ������ Ǯ��� ��
������ ������ �簢���� w, h�� �ִ�������ŭ �ݺ���
�ϳ��� �簢������ �߷����� ������ (���� + ���� - 1) => (����/�ִ����� + ����/�ִ����� -1)
��ü ������ (w*h) - (w/gcd + h/gcd - 1) => w*h - (w+h) + gcd
*/
//https://programmers.co.kr/learn/courses/30/lessons/62048?language=cpp
