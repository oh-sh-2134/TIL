#include<iostream>
#include<set>
#include<vector>

using namespace std;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	
	set<int> arr;
	int cnt = 1;
	for (auto it : A) {
		arr.insert(it);
	}
	
	for (auto it : arr)
	{
		if (it == cnt)
			cnt++;
		else
			return cnt;
	}
	return cnt;
}



int main(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(2);

	cout << solution(v);
}

// https://app.codility.com/demo/results/trainingYYSA9Q-2G3/
// 중복되지 않는 숫자만 들어온다는 것을 이용해서 set 사용
// 1부터 시작하기때문에 cnt와 비교해가며 check