#include <iostream>
using namespace std;
void hanoi(int n, int start, int to, int bypass)
{
    if(n == 1)
        printf("%d %d\n", start, to); // 가장 큰 원판만 남을 경우 1->3으로 이동
    else
    {
        hanoi(n-1,start,bypass,to); // n-1개의 원판을 1->2로 이동
        printf("%d %d\n",start,to);
        hanoi(n-1,bypass,to,start); // n-1개의 원판을 2->1로 이동
    }
}
int main() {
    int num;
    cin >> num;
    cout << (1<<num) -1 << "\n";
    hanoi(num,1,3,2);
}
//https://www.acmicpc.net/problem/11729
//핵심은 작은원판을 1 -> 2로 이동하는 것 하나
//가장 큰 원판을 1->3으로 이동, 나머지를 2->1로 이동시키는 재귀를 짜는게 중요함
//재귀함수로 푸는 문제를 연습을 좀 더 해봐야 할듯
//n-1이 결국 어떻게 되는지를 파악하는게 중요함