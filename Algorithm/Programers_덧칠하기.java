import java.util.*;
class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 0;
        int notPaintedPos =0;
        for (int pos : section) {
            if(notPaintedPos>pos) continue;
            notPaintedPos = pos + m;
            answer++;
        }
        return answer;
    }
}
class main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {2, 3, 6};
        System.out.println("sol = " + sol.solution(8,4,arr));
    }
}
//https://school.programmers.co.kr/learn/courses/30/lessons/161989