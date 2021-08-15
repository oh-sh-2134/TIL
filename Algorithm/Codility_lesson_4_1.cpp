#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int solution(int X, vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	unordered_set<int> leaf;
	unordered_set<int>::iterator it;
	int cnt = 0;
	for (auto element : A)
	{
		
		it = leaf.find(element);
		if (it == leaf.end())
			leaf.insert(element);

		if (leaf.size() == X)
			return cnt;

		cnt++;
	}
	return -1;
}

int main(void)
{
	vector<int>v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(4);
	cout << solution(5, v);
}

// https://app.codility.com/demo/results/trainingG4YGAA-ZVH/
// undrdered_set사용하여 원하는 거리에 닿는 것을 set.size로 판단하여 처리했다