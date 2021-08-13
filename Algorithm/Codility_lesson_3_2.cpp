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
// �ߺ����� �ʴ� ���ڸ� ���´ٴ� ���� �̿��ؼ� set ���
// 1���� �����ϱ⶧���� cnt�� ���ذ��� check