import java.util.*;
class Solution {
    public long solution(int[] sequence) {
        long[] sum = new long[sequence.length];
        long pre = 0, pulse = 1;
        long max = 0, min = 0;
        for (int i = 0; i < sequence.length; i++) {
            int seq = sequence[i];
            sum[i] = pre + pulse * seq;
            max = Math.max(max, sum[i]);
            min = Math.min(min, sum[i]);
            pre = sum[i];
            pulse *= -1;
        }
        return max - min;
    }
}
class main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {2, 3, -6, 1, 3, -1, 2, 4};
        System.out.println("sol = " + sol.solution(arr));
    }
}
//https://school.programmers.co.kr/learn/courses/30/lessons/161988