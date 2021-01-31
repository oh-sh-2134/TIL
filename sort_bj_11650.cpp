#include<iostream>

using namespace std;
int sorted_x[100000];
int sorted_y[100000];

void merge(int a[], int b[], int start, int middle, int end) {
	int i = start, j = middle + 1,p=start;
	while (i <= middle && j <= end) {
		if (a[i] > a[j]) {
			sorted_x[p] = a[j];
			sorted_y[p] = b[j];
			j++;
		}
		else if(a[i] < a[j]) {
			sorted_x[p] = a[i];
			sorted_y[p] = b[i];
			i++;
		}
		else  {
			if (b[i]>b[j]) {
				sorted_x[p] = a[j];
				sorted_y[p] = b[j];
				j++; 
			}
			else {
				sorted_x[p] = a[i];
				sorted_y[p] = b[i];
				i++;
			}
		}
		p++;
	}
	if (i > middle) {
		for (int c = j; c <= end; c++) {
			sorted_x[p] = a[c];
			sorted_y[p] = b[c];
			p++;
		}
	}
	else {
		for (int c = i; c <= middle; c++) {
			sorted_x[p] = a[c];
			sorted_y[p] = b[c];
			p++;
		}
	}
	for (int c = start; c <= end; c++) {
		a[c] = sorted_x[c];
		b[c] = sorted_y[c];
	}
}

void merge_sort(int a[], int b[], int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		merge_sort(a, b, start, middle);
		merge_sort(a, b, middle + 1, end);
		merge(a, b, start, middle, end);
	}
}

int main(void) {
	int N, x[100000], y[100000];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	merge_sort(x, y, 0, N-1 );
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", x[i],y[i]);
	}
}

//https://www.acmicpc.net/problem/11650
//간단한거같은데 조금 거렸음