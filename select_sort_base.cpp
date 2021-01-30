#include<iostream>
#include<vector>

using namespace std;

int main() {
	int temp = 0;
	int pattern[10] = { 4,1,2,7,9,8,6,5,0,3 };
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			if (pattern[i] > pattern[j]) {
				temp = pattern[i];
				pattern[i] = pattern[j];
				pattern[j] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d", pattern[i]);
	}
}