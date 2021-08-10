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
//https://app.codility.com/demo/results/trainingTXDEAJ-5A2/   //���

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
// �ڵ尳�� and ������ ���� �ڿ������� ī������ �����ϴ� �Ͱ� 2���� ���鶧 ��Ʈ������ >> ����ϴ°��� �λ����
// cntflag�� ������� �ʰ� �� ����ϰ� ¥�����ߴµ� 32�� ���� ī������ ���� ���ڿ� ���� ó���� �ȵ�
// ������ N == 1 && maxGap == 0 �϶� 0�� return �ع����� �ڵ带 © �� �ֱ��ѵ� N�� maxGap�� ���� ���� and���꺸�� 
// �׳� cntflag�ϳ��� ���°� ���굵 ���� �������� ���� ������ �����ؼ� ������