#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int sol = 1;
	sort(A.begin(), A.end());
	for (auto element : A)
	{
		if (element == sol)
			sol++;
		else
			return 0;
	}
	return 1;
}


int main(void)
{
	vector<int>v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	cout << solution(v);

}

// https://app.codility.com/demo/results/training9J6CY6-SV4/