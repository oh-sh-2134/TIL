import java.util.*;

class Solution {
    public int solution(String t, String p) {
        int len = p.length();
        long num = Long.parseLong(p);
        int result = 0;

        for (int i = 0; i < t.length() - len + 1; i++) {
            long diff = Long.parseLong(t.substring(i, i + len));
            if (diff <= num) result++;
        }
        return result;
    }
}

class main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        String t = "3141592";
        String p = "271";
        System.out.println("sol = " + sol.solution(t,p));
    }

}
