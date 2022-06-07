#include<iostream>
#include<queue>
#include <algorithm>
#include<functional>

#define MAX 100004

using namespace std;

int t;
int arr[MAX];

priority_queue<int, vector<int>, less<int>> max_heap; 
priority_queue<int, vector<int>, greater<int>> min_heap;


void input() {
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> arr[i];
}

void solution() {
	for (int i = 0; i < t; i++) {
		if (max_heap.size() == min_heap.size())
			max_heap.push(arr[i]);
		else
			min_heap.push(arr[i]);
		if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
			int max_val, min_val;
			max_val = max_heap.top();
			min_val = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(min_val);
			min_heap.push(max_val);


		}
		cout << max_heap.top() << '\n';
	}
}

int main(void) {
	input();
	solution();
}
//https://www.acmicpc.net/problem/1655