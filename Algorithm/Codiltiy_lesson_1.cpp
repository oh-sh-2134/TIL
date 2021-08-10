#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
	// write your code in C++14 (g++ 6.2.0)
	string strnum = "";
	int first = -1, second = -1;
	int sol = 0;
	while (N)
	{
		if (N % 2 == 1)
		{
			strnum.append("1");
		}
		else
		{
			strnum.append("0");
		}
		N = N / 2;
	}
	for (int i = strnum.size()-1; i>=0 ; i--)
	{
		if (strnum[i] == '1')
		{
			if (first == -1)
				first = i;
			else if (second == -1)
				second = i;
			else
			{
				first = second;
				second = i;
			}

			if (first != -1 && second != -1)
			{
				sol = max(first - second - 1,sol);
			}
		}
	}
	return sol;
}

int main(void)
{
	int a;
	cin >> a;
	cout << solution(a);
	

}
//https://app.codility.com/demo/results/trainingTXDEAJ-5A2/   //결과

int solution(int N)
{
	int maxGap = 0;
	int Gap = 0;
	bool cntflag = false;

	while (N) {
		if ((N & 1) == 1)
		{
			if (!cntflag)
			{
				cntflag = true;
			}
			else if (Gap > maxGap)
			{
				maxGap = Gap;
			}
			Gap = 0;
		}
		else {
			Gap++;
		}
		N = N >> 1;
	}
	return maxGap;
}

// https://app.codility.com/demo/results/training4WW8JU-Z2U/
// 코드개선 and 연산을 통해 뒤에서부터 카운팅을 시작하는 것과 2진수 만들때 비트연산자 >> 사용하는것이 인상깊음
// cntflag를 사용하지 않고 더 깔끔하게 짜보려했는데 32와 같이 카운팅이 없는 숫자에 대한 처리가 안됨
// 억지로 N == 1 && maxGap == 0 일때 0을 return 해버리는 코드를 짤 수 있긴한데 N과 maxGap을 각각 비교후 and연산보다 
// 그냥 cntflag하나를 쓰는게 연산도 적고 가독성도 좋지 않을까 생각해서 선택함