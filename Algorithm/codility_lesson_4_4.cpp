#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
	int check = 1;
	sort(A.begin(),A.end());
	for(auto element: A){
		if(element == check)
			check++;
		else 
			return 0;
	}
	return 1;
}


int main(void){
	vector<int>v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	cout << solution(v);
}

//https://app.codility.com/demo/results/trainingYBQBZ3-K4V/