#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	//오름차순 배열과 내림차순 배열을 순서대로 곱하면 됨
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), cmp);

	int sum = 0;
	for (int i = 0; i < A.size(); i++) {
		answer += A[i] * B[i];
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12941