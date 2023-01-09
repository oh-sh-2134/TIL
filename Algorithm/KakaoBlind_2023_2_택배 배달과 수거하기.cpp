#include <string>
#include <vector>
#include <stack>
using namespace std;


long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	long long answer = 0;
	stack<int> deliveriesInfo, pickupsInfo;
	for (int i = 0; i < deliveries.size(); i++) {
		deliveriesInfo.push(deliveries[i]);
		pickupsInfo.push(pickups[i]);
	}
	//최대거리의 택배 상자 존재 여부 체크
	while (!deliveriesInfo.empty()) {
		if (deliveriesInfo.top()) {
			break;
		}
		deliveriesInfo.pop();;
	}

	while (!pickupsInfo.empty()) {
		if (pickupsInfo.top()) {
			break;
		}
		pickupsInfo.pop();
	}

	int package = 0;
	auto max = [](int a, int b)->int {return a > b ? a : b; };
	while (!(deliveriesInfo.empty() && pickupsInfo.empty()))
	{
		//배달, 수거중 최대거리에 있는 집 방문시 왕복거리
		answer += max(deliveriesInfo.size() * 2, pickupsInfo.size() * 2);

		package = 0;
		while (!deliveriesInfo.empty() && package <= cap)
		{
			//최대거리의 집에 모두 배달 가능 케이스
			if (cap - deliveriesInfo.top() - package >= 0) {
				package += deliveriesInfo.top();
				deliveriesInfo.pop();
				continue;
			}
			//최대거리 집에 일부 배달 케이스
			deliveriesInfo.top() -= (cap - package);
			break;
		}

		package = 0;
		while (!pickupsInfo.empty() && package <= cap)
		{
			//최대거리의 집에 모두 수거 가능 케이스
			if (cap - pickupsInfo.top() - package >= 0) {
				package += pickupsInfo.top();
				pickupsInfo.pop();
				continue;
			}
			//최대거리의 집에 일부 수거 가능 케이스
			pickupsInfo.top() -= (cap - package);
			break;
		}
	}
	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/150369