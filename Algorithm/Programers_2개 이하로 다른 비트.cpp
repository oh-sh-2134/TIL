#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	for (auto iter : numbers) {
		long long bit = 1;
		if (iter & bit) {
			//홀수일때는 연속된 1의 개수가 n일때 n-1자리만큼 비트 수를 더하면 됨
			while (true) {
				if ((iter & bit) == 0) break;
				bit <<= 1;
			}
			bit >>= 1;
			answer.push_back(iter + bit);
		}
		else {
			//짝수일때는 가장 오른쪽 비트가 0이기 때문에 1만 더해주면 비트가 1개만 차이남
			answer.push_back(iter + bit);
		}
	}
	return answer;
}