#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	int mok = s / n;
	int namerge = s % n;
	//몫이 0일경우 불가능
	if (!mok) return { -1 };

	answer.resize(n, mok);

	for (int i = n; i > n - namerge; i--) {
		answer[i - 1]++;
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12938