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
// big 1, big 2���� Performance 50% -> Total 77%
// set�� �ð� ���⵵ -> �˻� O(logn) , ���� ���� O(logn + a)
// ���������� O(N**2)�� ���� ����

//https://app.codility.com/demo/results/training34KPE2-QM2/
// unordered_set������� Performance 100 -> Total 100%
// unordered_set�� �ð� ���⵵ -> O(1) ~ O(N)
// ���������� O(N) or O(N*log(N)) �� ���� ����
// unordered_set����� C++ 11 �̻󿡼� ��� ����

//https://hydroponicglass.tistory.com/171
//����