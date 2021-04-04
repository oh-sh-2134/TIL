#include<iostream>

#define MAX 10
using namespace std;
int sorted[10];

void merge_f(int arry[], int start, int middle, int end) {
	int i = start, j = middle + 1, k=start;
	while (i <= middle && end >= j) {
		if (arry[i] <= arry[j]) {
			sorted[k++] = arry[i];
			i++;
		}
		else if (arry[i] >= arry[j]) {
			sorted[k++] = arry[j];
			j++;
		}
	}
	if (i > middle) {
		for (int c = j; c <= end; c++) {
			sorted[k++] = arry[c];
		}
	}
	else {
		for (int c = i; c <= middle; c++) {
			sorted[k++] = arry[c];
		}
	}
	
	for (int i = 0; i <= end; i++) {
		arry[i] = sorted[i];
	}
}

void divied(int arry[], int start, int end) {
	if (start < end) {
		int middle = (start+end) / 2;
		divied(arry, start, middle);
		divied(arry, middle + 1, end);
		merge_f(arry, start, middle, end);
	}
}

int main() {
	int arry[MAX] = { 4, 1, 2, 7, 9, 8, 6, 5, 0, 3 };
	divied(arry, 0, MAX-1);
	for (int i = 0; i < MAX; i++) {
		cout << arry[i];
	}
}

//merge_sort 이전에 엄청 헤매다 감 잡았는데
//다시하려니까 이론은 알지만 코딩미스가 많이 나서 조금 오래걸림