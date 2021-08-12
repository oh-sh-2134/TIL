#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;


int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	/*
	set<int> s;
	set<int>::iterator it;
	*/

	unordered_set<int> s;
	unordered_set<int>::iterator it;

	for(auto element : A)
	{
		it = s.find(element);
		if (it == s.end())
			s.insert(element);
		else
			s.erase(it);
	}

	int sol = *s.begin();

	return sol;
}

int main(void)
{
	vector<int> v;
	v.push_back(9);
	v.push_back(3);
	v.push_back(9);
	v.push_back(3);
	v.push_back(7);
	v.push_back(4);
	v.push_back(4);

	solution(v);
}

//https://app.codility.com/demo/results/trainingX5C2ZH-DH7/
// big 1, big 2에서 Performance 50% -> Total 77%
// set의 시간 복잡도 -> 검색 O(logn) , 삽입 삭제 O(logn + a)
// 문제에서는 O(N**2)로 보고 있음

//https://app.codility.com/demo/results/training34KPE2-QM2/
// unordered_set사용으로 Performance 100 -> Total 100%
// unordered_set의 시간 복잡도 -> O(1) ~ O(N)
// 문제에서는 O(N) or O(N*log(N)) 로 보고 있음
// unordered_set사용은 C++ 11 이상에서 사용 가능

//https://hydroponicglass.tistory.com/171
//참고