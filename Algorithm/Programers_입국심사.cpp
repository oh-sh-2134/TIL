#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	//이분탐색을 위한 정렬
	sort(times.begin(), times.end());
	//범위의 최소값
	long long start = 1;
	//범위의 최댓값
	long long end = (long long)times[times.size() - 1] * n;
	long long mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		long long temp = 0;

		//해당 시간안에 심사를 받을 수 있는 사람의 최솟값을 구함
		for (auto iter : times)
			temp += (mid / iter);

		//사람이 부족하다면 최솟값을 늘려야함
		if (temp < n) {
			start = mid + 1;
			continue;
		}
		//현재까지의 최솟값을 저장해 둠
		if (mid <= end)
			answer = mid;

		//사람이 남는다면 최댓값을 줄여야함
		end = mid - 1;

	}
	return answer;
}
//https://programmers.co.kr/learn/courses/30/lessons/43238