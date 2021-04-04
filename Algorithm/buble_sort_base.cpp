#include<iostream>
#include<stdio.h>
#define MAX 10
using namespace std;

int main() {
	int arry[10]={ 4, 1, 2, 7, 9, 8, 6, 5, 0, 3 };
	int temp,max=0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 1; j < MAX-i; j++) {
			if (arry[j - 1] > arry[j]) {
				temp = arry[j - 1];
				arry[j - 1] = arry[j];
				arry[j] = temp;
			}
		}
	}
	for (int i = 0; i < MAX; i++) {
		cout<<arry[i];
	}
}