#include <iostream>

using namespace std;
int main(void) { 
	int i, num1, num2, n1, n2; 
	cin >> num1>> num2; 
	n1 = (num1 / 100) + (num1 / 10 % 10 * 10) + (num1 % 10 * 100); 
	n2 = (num2 / 100) + (num2 / 10 % 10 * 10) + (num2 % 10 * 100); 
	if(n1 > n2) cout<< n1;
	else cout << n2; 
	return 0; 
}
//https://www.acmicpc.net/problem/2908
//²ÙÁØÈ÷..