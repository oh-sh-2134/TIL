#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
/*
int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int sol = 1;
	set<int>s;
	for (auto element : A)
	{
		s.insert(element);
	}
	
	for (auto element : s)
	{
		if (element == sol)
			sol++;
	}
	return sol;
}
*/
int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int sol = 1;
	sort(A.begin(), A.end());
	for (auto element : A)
	{
		if (element == sol)
			sol++;
	}
	return sol;
}


int main(void)
{
	vector<int>v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	cout << solution(v);

}
