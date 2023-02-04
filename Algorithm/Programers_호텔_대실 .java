import java.util.*;

class Solution {
    private final static int CLEAN_TIME = 10;
    private final static int HOUR_TO_MIN = 60;
    private final static int MAX_MIN = 24*HOUR_TO_MIN+CLEAN_TIME;

    int [] timestamp = new int[1451];

    protected int getMin(String stringTime) {
        String [] rst = stringTime.split(":");
        int min =Integer.parseInt(rst[0])*HOUR_TO_MIN + Integer.parseInt(rst[1]);
        return min;
    }

    public int solution(String[][] book_time) {
        int answer = 0;
        Arrays.fill(timestamp,0);
        for (String[] book : book_time) {
            int startTime = getMin(book[0]);
            int endTime = getMin(book[1])+CLEAN_TIME;
            timestamp[startTime]++;
            timestamp[endTime]--;
        }
        for (int i = 1;i<MAX_MIN; i++) {
            timestamp[i] += timestamp[i-1];
        }
        for (int i : timestamp) {
            if(answer<i) answer = i;
        }
        return answer;
    }
}

class Programers_호텔_대실{

    public static void main(String[] args) {
        Solution sol = new Solution();
        String[][] s ={{"09:10", "10:10"}, {"10:20", "12:20"}};
        System.out.println("sol = " + sol.solution(s));
    }

}
