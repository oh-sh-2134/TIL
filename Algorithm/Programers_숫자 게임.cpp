#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0, j = 0; i < A.size() && j < B.size(); i++, j++) {
		while (j < B.size()) {
			if (A[i] < B[j]) {
				answer++;
				break;
			}
			j++;
		}
	}

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12987