import java.util.*;
class Solution {
    public int solution(int a, int b, int n) {
        //return (n - b) / (a - b) * b;
        int answer = 0;
        while(n>=a){
            int cola = (n/a)*b;
            answer += cola;
            n = n%a + cola;
        }
        return answer;
    }
}
class main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "banana";
        System.out.println("sol = " + sol.solution(10,3,2));
    }
}
//https://school.programmers.co.kr/learn/courses/30/lessons/132267