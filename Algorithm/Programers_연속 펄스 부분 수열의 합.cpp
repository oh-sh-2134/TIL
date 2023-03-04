#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
	auto max = [](long long a, long long b)->long long {return a > b ? a : b; };
	auto max3 = [](long long a, long long b, long long c)->long long { long long temp = a > b ? a : b; return temp > c ? temp : c; };
	vector<long long> upPulse(sequence.size(), 0);
	vector<long long> downPulse(sequence.size(), 0);

	downPulse[0] = -sequence[0];
	upPulse[0] = sequence[0];

	long long answer = max(downPulse[0], upPulse[0]);

	for (long long i = 1; i < sequence.size(); i++) {
		if (i & 1) {
			downPulse[i] = max(downPulse[i - 1] + sequence[i], sequence[i]);
			upPulse[i] = max(upPulse[i - 1] - sequence[i], -sequence[i]);
		}
		else {
			downPulse[i] = max(downPulse[i - 1] - sequence[i], -sequence[i]);
			upPulse[i] = max(upPulse[i - 1] + sequence[i], sequence[i]);
		}
		answer = max3(upPulse[i], downPulse[i], answer);
	}
	return answer;
}
int main(void) {
	vector<int> v = { 2, 3, -6, 1, 3, -1, 2, 4 };
	solution(v);
}
//https://school.programmers.co.kr/learn/courses/30/lessons/161988