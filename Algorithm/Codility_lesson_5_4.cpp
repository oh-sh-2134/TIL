#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	double minAvg = (A[0] + A[1]) / 2.0;
	double Avg = 0;
	int sol = 0;

	for (int i = 2; i < A.size(); i++) {

		Avg = (A[i - 2] + A[i - 1] + A[i]) / 3.0;
		if (minAvg > Avg)
		{
			minAvg = Avg;
			sol = i - 2;
		}
		
		Avg = (A[i - 1] + A[i]) / 2.0;
		if (minAvg > Avg)
		{
			minAvg = Avg;
			sol = i - 1;
		}

	}

	return sol;
}


int main(void)
{
	vector<int>v;
	v.push_back(4);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(1);
	v.push_back(5);
	v.push_back(8);

	cout << solution(v);

}

// https://app.codility.com/demo/results/training9J6CY6-SV4/