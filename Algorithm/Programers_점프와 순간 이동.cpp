#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 0;

	while (n) {
		//¦���� �ƴҶ��� ¦���� ������ָ� ��
		if (n % 2 != 0) {
			n--;
			ans++;
		}
		n /= 2;

	}

	return ans;
}
//https://programmers.co.kr/learn/courses/30/lessons/12980