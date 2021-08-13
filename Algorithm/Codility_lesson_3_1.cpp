#include<iostream>

using namespace std;

int solution(int X, int Y, int D) {
	// write your code in C++14 (g++ 6.2.0)
	int cnt = 0;
	int dist = Y - X;
	if (D < Y)
		cnt = dist % D == 0 ? dist / D : dist / D + 1;
	else if (D == Y)
		cnt = 1;

	return cnt;
}



int main(void)
{
	int X = 10, Y = 85, D = 30;
	cin >> X >> Y >> D;
	cout << solution(X,Y,D);
}

// https://app.codility.com/demo/results/trainingFV3SN9-35N/
// 너무 쉬워서 풀이가 맞는지 당황스러웠다.