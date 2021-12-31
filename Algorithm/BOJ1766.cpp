#include<iostream>
#include<queue>
#include<vector>
#define MAX 32001

using namespace std;

int num[MAX];
vector<int> v[MAX];
bool visited[MAX];
int N, M;

void Input() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		num[b]++;
	}
}

void solution() {
	int cnt = 0;


	while (cnt<N) {
		int current;
		
		for (int i = 1; i <= N; i++) {
			if (num[i] == 0 && !visited[i]) {	
				current = i;
				cout << i << " ";
				visited[i] = true;
				cnt++;
				break;
			}
	
		}
		for (int i = 0; i < v[current].size(); i++) {
			num[v[current][i]]--;
		}
	}
}

int main() {
	Input();
	solution();
}
//https://www.acmicpc.net/problem/1766