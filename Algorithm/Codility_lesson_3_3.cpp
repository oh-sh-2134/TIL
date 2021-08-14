#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	vector<int> frond_sum(A.size());
	vector<int> reverse_sum(A.size());
	int min = 987654321;
	int P = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (i == 0)
			frond_sum[i] = A[i];
		else
			frond_sum[i] = frond_sum[i - 1] + A[i];
	}
	for (int i = A.size() - 1; i >= 0; i--)
	{
		if (i == A.size()-1)
			reverse_sum[i] = A[i];
		else
			reverse_sum[i] = reverse_sum[i + 1] + A[i];
	}
	for (int i = 1; i < A.size(); i++)
	{
		if (abs(frond_sum[i - 1] - reverse_sum[i]) < min) {
			min = abs(frond_sum[i - 1] - reverse_sum[i]);
		}
	}
	return min;

}


int main(void) {
	vector<int> a;
	a.push_back(3);
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(3);

	cout << solution(a);
}

// https://app.codility.com/demo/results/trainingU5TPMK-A3A/
// 앞에서부터 더해간 front_sum와 반대로 뒤에서 부터 더해온 reverse_sum을 만들고,
// frond_sum[i - 1] - reverse_sum[i]으로 연산해 나가면서 P를 구함
// DP(?)를 활용하려 했고 3*O(N)인데 상수 곱셈을 빼면 O(N)으로 구현 함