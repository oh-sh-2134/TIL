import java.util.*;

class Solution {
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int n, m;
    static boolean[][] visited;
    static int[][] arr;

    public int[] solution(String[] maps) {
        List<Integer>al = new ArrayList<>();
        n = maps.length;
        m = maps[0].length();

        arr = new int[n][m];
        visited = new boolean[n][m];

        for(int i = 0; i < n; i++){
            String str = maps[i];
            for(int j = 0; j < m; j++){
                if(str.charAt(j) != 'X'){
                    arr[i][j] = str.charAt(j) - '0';
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] > 0 && !visited[i][j]){
                    al.add(bfs(i, j));
                }
            }
        }

        if(al.size() == 0){
            return new int[] {-1};
        }
        Collections.sort(al);
        int[] answer = new int[al.size()];

        for(int i = 0; i < al.size(); i++){
            answer[i] = al.get(i);
        }

        return answer;
    }

    public int bfs(int r, int c){
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[] {r, c});
        visited[r][c] = true;
        int sum = arr[r][c];

        while(!q.isEmpty()){
            int[] now = q.poll();

            for(int i = 0; i < 4; i++){
                int nr = now[0] + dx[i];
                int nc = now[1] + dy[i];

                if(nr >= n || nc >= m || nr < 0 || nc < 0 || visited[nr][nc] || arr[nr][nc] == 0) continue;

                sum += arr[nr][nc];
                visited[nr][nc] = true;
                q.offer(new int[] {nr, nc});
            }
        }
        return sum;
    }
}

class main{

    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] s ={"X591X","X1X5X","X231X", "1XXX1"};
        System.out.println("sol = " + sol.solution(s));
    }

}
