import java.util.*;

class Solution {
    int mx[] = {0,0,1,-1};
    int my[] = {1,-1,0,0};
    public int solution(int[][] maps) {
        int answer = -1;
        int visited[][] = new int[maps.length][maps[0].length];
        Queue<int []>q = new LinkedList<>();
        q.add(new int []{0,0});
        visited[0][0] = 1;
        while (!q.isEmpty()) {
            int[] cur = q.remove();
            int curY = cur[0];
            int curX = cur[1];
            for (int i =0 ;i<4;i++) {
                int ny = curY + my[i];
                int nx = curX + mx[i];
                if (ny > maps.length-1 || ny < 0 || nx > maps[0].length-1 || nx < 0) continue;
                if(maps[ny][nx] == 1 && visited[ny][nx] ==0){
                    visited[ny][nx] = visited[curY][curX] +1;
                    q.add(new int[]{ny,nx});
                }
            }
        }
        if(visited[maps.length-1][maps[0].length-1]>0)
            answer = visited[maps.length-1][maps[0].length-1];

        return answer;
    }
}
