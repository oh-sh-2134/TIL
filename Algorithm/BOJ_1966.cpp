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
		//����Ʈ ť���� �켱������ ���ʴ�� �����ϴ� �켱 ť
		priority_queue<int> pq;
		//�۾��� �켱������ �۾��� ������ ���� ť
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
			//���� �ֿ켱 ������ ���� �۾��� ������ �´��� Ȯ��
			if (priority != pq.top()) {
				q.push({ priority,pos });
				continue;
			}
			//�ֿ켱 ������ �۾��� ����Ǿ���
			pq.pop();
			cnt++;
			//ã�� �۾��� �Ϸ�Ǿ�����
			if (pos == m) {
				cout << cnt << "\n";
				break;
			}
			
		}
	}
}
//https://www.acmicpc.net/problem/1966