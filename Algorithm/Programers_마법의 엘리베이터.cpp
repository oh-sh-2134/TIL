#include <string>
#include <vector>
using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey){
        int idx = storey%10;
        storey/=10;
        if(idx>=5){ 
            idx = 10 -idx;
            if(idx == 5 && (storey%10) <5)
                storey-=1;
            storey += 1;
            
        }
        answer+=idx;
    }
    return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/148653#
