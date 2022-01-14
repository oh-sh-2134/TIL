#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 1001

using namespace std;

int indegree[MAX];
vector<int> adj[MAX];
pair<int,int> strahler[MAX];
int t, k, m, p,sol;


int main(void) {

	cin >> t;
	while (t--) {
		cin >> k >> m >> p;
		sol = 0;
		for (int i = 0; i <= m; i++) {
			adj[i].clear();
			strahler[i] = { 0,0 };
			indegree[i] = 0;
		}

		for (int i = 0; i < p; i++) {
			int a, b;
			cin >> a >> b;
			indegree[b]++;
			adj[a].push_back(b);
		}



		queue<int>q;

		for (int i = 1; i <= m; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				strahler[i] = { 1,1 };
			}
		}
		for (int i = 1; i <= m; ++i) {
			int current = q.front();
			q.pop();

			for (auto next : adj[current]) {

				if (strahler[next].first < strahler[current].first)
					strahler[next] = { strahler[current].first,1 };


				else if (strahler[next].first == strahler[current].first)
					strahler[next].second++;

				if (--indegree[next] == 0) {
					q.push(next);
					if (strahler[next].second > 1)
						strahler[next] = { strahler[next].first + 1,1 };
				}

			}
		}

		cout << k << " " << strahler[m].first << "\n";
	}

	return 0;
}
//https://www.acmicpc.net/problem/9470