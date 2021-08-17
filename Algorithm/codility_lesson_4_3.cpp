#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
/*
int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	
	set<int> arr;
	int cnt = 1;
	for (auto it : A) {
		if(it>0)
			arr.insert(it);
	}
	for (auto it : arr)
	{
		if (it == cnt)
			cnt++;
	}
	return cnt;
}
*/

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	
	int cnt = 1;
	sort(A.begin(),A.end());
	for (auto it : A)
	{
		if (it == cnt)
			cnt++;
	}
	return cnt;
}

int main(void)
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	//v.push_back(6);


	cout << solution(v);
}


//https://app.codility.com/demo/results/trainingQ5QRVU-F49/


//https://app.codility.com/demo/results/trainingFX5XBH-P6J/
//º¤ÅÍÀÌ¿ë