import java.util.*;
class Solution {
    public int[] solution(String[] wallpaper) {
        int MAX_X=Integer.MIN_VALUE,MIN_X=Integer.MAX_VALUE,MAX_Y=Integer.MIN_VALUE,MIN_Y=Integer.MAX_VALUE;
        for(int y=0;y< wallpaper.length;y++) {
            for (int x = 0; x < wallpaper[y].length(); x++) {
                if (wallpaper[y].charAt(x) != '#')
                    continue;

                MAX_X = Math.max(MAX_X,x);
                MIN_X = Math.min(MIN_X,x);
                MAX_Y = Math.max(MAX_Y,y);
                MIN_Y = Math.min(MIN_Y,y);

            }
        }
        int[] answer = {MIN_Y, MIN_X, MAX_Y + 1, MAX_X + 1};
        return answer;
    }
}
class main{
    public static void main(String[] args) {
        Solution sol = new Solution();
        String wallpaper[] = {".#...", "..#..", "...#."};
        System.out.println("sol = " + sol.solution(wallpaper));
    }
}
//https://school.programmers.co.kr/learn/courses/30/lessons/161990