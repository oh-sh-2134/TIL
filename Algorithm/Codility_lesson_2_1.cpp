#include<iostream>
#include<vector>

using namespace std;


vector<int> solution(vector<int> &A, int K) {
	// write your code in C++14 (g++ 6.2.0)
	vector<int>::iterator it;

	if (A.empty())
	{
		return A:
	}
		

	while (K--) {

		it = A.begin();
		A.insert(it, A.back());
		A.pop_back();

	}
	return A;


}


int main(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	solution(v, 3);
}

//https://app.codility.com/demo/results/trainingT5GDMG-99V/
//벡터가 비어 있는 케이스가 빠짐

//https://app.codility.com/demo/results/trainingQ84FK9-BXT/
//100점 확인
