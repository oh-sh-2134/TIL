import java.util.*;
import java.util.stream.IntStream;
class Solution {
    private Integer getYakSu(int number, int limit, int power){
        Integer cnt =0;
        for (int i = 1; i * i <= number; i++) {
            if (i * i == number) cnt++;
            else if (number % i == 0) cnt += 2;
        }
        return cnt > limit ? power : cnt;
    }

    public int solution(int number, int limit, int power) {
        return IntStream.range(1,number+1).reduce(0,(total,n) -> total + getYakSu(n,limit,power));
    }
}
class main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "banana";
        System.out.println("sol = " + sol.solution(10,3,2));
    }
}
//https://school.programmers.co.kr/learn/courses/30/lessons/136798