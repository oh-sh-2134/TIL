#include<iostream>
using namespace std;

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
	int a = A%K != 0 ? A/K : A/K -1;
	int b = B/K;
	return b-a;
}

//https://app.codility.com/demo/results/trainingBEWSZA-PQY/