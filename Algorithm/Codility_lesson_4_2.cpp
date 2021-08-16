#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

/*
vector<int> solution(int N, vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	vector<int>v(N,0);
	int maxidx = 0;
	for (auto it : A)
	{
		if (it == N + 1)
			v.assign(N, maxidx);
		else
		{
			v[it - 1] ++;
		}

		if (v[it - 1] > maxidx)
			maxidx = v[it - 1];
		
	}
	return v;
}
*/

vector<int> solution(int N, vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	vector<int>v(N, 0);
	int increase = 0;
	int max = 0;
	for (auto it : A)
	{
		if (it == N + 1)
			increase = max;
		else
		{
			if (v[it - 1] < increase)
				v[it - 1] = increase + 1;
			else
				v[it - 1]++;

			if (v[it - 1] > max)
				max = v[it - 1];
		}

	}
	for (int i = 0; i <v.size(); i ++)
	{
		if (v[i] < increase)
			v[i] = increase;
	}
	return v;
}
int main(void)
{
	vector<int>v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	v = solution(1, v);
	int sum = 0;
	for (auto it : v)
	{
		cout << it << " ";
	}
}

// https://app.codility.com/demo/results/trainingGGREYP-J8B/
// �ð��ʰ��� �����̰� ,���� �߸��� ���� �ִµ���...

// https://app.codility.com/demo/results/trainingA6NCYH-82Y/
// �ð��ʰ��ذ� �� �����ذ�