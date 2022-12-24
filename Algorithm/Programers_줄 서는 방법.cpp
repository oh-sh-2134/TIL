#include <vector>
#include <iostream>
using namespace std;

vector<int> answer;
vector<int> nums;
int N;

long long factorial(int n)
{
	long long fac = 1;
	while (n)
	{
		fac *= n;
		n--;
	}
	return fac;
}

void combine(long long n, long long k)
{
	if (n == 0)
	{
		answer.push_back(nums[0]);
		return;
	}
	long long nfactorial = factorial(n);
	answer.push_back(nums[k / nfactorial]);
	nums.erase(nums.begin() + (k / nfactorial));
	combine(n - 1, k % nfactorial);
}

vector<int> solution(int n, long long k)
{
	for (int i = 1; i <= n; i++)
		nums.push_back(i);
	combine(n - 1, k - 1);

	return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/12936