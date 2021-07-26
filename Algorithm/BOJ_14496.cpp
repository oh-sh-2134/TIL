#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;
 
vector<pair<int, int> > list[1001];
int d[1001];
int N, M, start, des;
 
void dijkstra() {
    d[start] = 0;
    priority_queue<pair<int, int> > q;
    q.push({ start, 0 });
    while (!q.empty()) 
    {
        int x = q.top().first;
        int dis = -q.top().second;
        q.pop();
 
        if (d[x] < dis) continue;
 
        for (int i = 0; i < list[x].size(); i++) 
        {
            int next = list[x][i].first;
            int nextdis = dis + list[x][i].second;
 
            if (d[next] > nextdis) 
            {
                d[next] = nextdis;
                q.push({ next, -nextdis });
            }
        }
    }
    if (d[des] == INF) cout << "-1\n";
    else cout << d[des] << '\n';
}
 
void init() {
    for (int i = 1; i <= N; i++) 
    {
        d[i] = INF;
    }
}
 
void input() {
    int u, v;
    cin >> start >> des >> N >> M;
    init();
 
    while (M--) 
    {
        cin >> u >> v;
        list[u].push_back({ v,1 });
        list[v].push_back({ u,1 });
    }
}
 
int main() {

 
    input();
    dijkstra();
 
    return 0;
}


//https://www.acmicpc.net/problem/14496
//다익스트라 알고리즘 공부 필요함
//다익스트라 알고리즘으로 1
