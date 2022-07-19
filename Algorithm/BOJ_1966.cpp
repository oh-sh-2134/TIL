#include<iostream>
#include<queue>

using namespace std;

int t;

int main(void) {
	cin >> t;
	
	while (t--) {
		int n, m;
		int cnt = 0;
		cin >> n >> m;
		//프린트 큐에서 우선순위를 차례대로 정렬하는 우선 큐
		priority_queue<int> pq;
		//작업의 우선순위와 작업의 순서를 담을 큐
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			pq.push(k);
			q.push({ k,i });
		}
	
		while (true) {
			int priority = q.front().first;
			int pos = q.front().second;
			q.pop();
			//현재 최우선 순위와 현재 작업의 순위가 맞는지 확인
			if (priority != pq.top()) {
				q.push({ priority,pos });
				continue;
			}
			//최우선 순위의 작업이 수행되었음
			pq.pop();
			cnt++;
			//찾는 작업이 완료되었을때
			if (pos == m) {
				cout << cnt << "\n";
				break;
			}
			
		}
	}
}
//https://www.acmicpc.net/problem/1966