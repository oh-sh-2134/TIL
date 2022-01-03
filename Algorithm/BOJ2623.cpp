#include<iostream>
#include<queue>
#include<vector>
#define MAX 1001
using namespace std;

int singer[MAX];
bool checkDuplication[MAX][MAX];
vector<int> adj[MAX];

int n, m;
void Input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cnt;
		int previous = 0;
		int input = 0;
		cin >> cnt >> previous;
		
		while(--cnt){
			cin >> input;
			if (!checkDuplication[previous][input]) {
				checkDuplication[previous][input] = true;
				adj[previous].push_back(input);
				singer[input]++;
				previous = input;
			}
		}
	}
}

void solution() {
	queue<int>q;
	int cnt = 0;
	for (int i = 1; i <= n; i++) 
		if (singer[i] == 0)
			q.push(i);
	if (q.empty()) 
		cout << "0";
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current<<"\n";
		for (auto iter : adj[current]) {
			int next = iter;
			if (--singer[next] == 0)
				q.push(next);
		}
	}
}


int main(void) {
	Input();
	solution();
}

//Âü°í
//https://www.acmicpc.net/board/view/38847