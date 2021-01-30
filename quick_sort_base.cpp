#include<iostream>
#define MAX 10
int arry[MAX] = { 4, 1, 2, 7, 9, 8, 6, 5, 0, 3 };

using namespace std;
void quick_sort(int *data,int start,int end){
	if (start >= end) return;
	int i = start+1, j = end, key = start;
	int temp;
	while (j>=i) {
		while (j>start && data[key] <= data[j]) {
			j--;
		}
		while (i<=end &&data[key] >= data[i]) {
			i++;
		}
		if (i > j) {
			temp = data[key];
			data[key] = data[j];
			data[j] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quick_sort(data, start, j-1);
	quick_sort(data, j+1, end);
}

int main() {
	int start = 0;
	quick_sort(arry, 0,MAX-1);
	for (int i = 0; i < MAX; i++) {
		cout<<arry[i];
	}
	
}