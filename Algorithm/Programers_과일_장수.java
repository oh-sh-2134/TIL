import java.util.*;

class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());
        for (int i : score) {
            if(i>k) continue;
            priorityQueue.add(i);
        }
        while(priorityQueue.size()>=m){
            for(int i=1;i<m;i++) priorityQueue.remove();
            answer += priorityQueue.poll()*m;
        }
        return answer;
    }
}

//import java.util.Arrays;
//import java.util.Collections;
//import java.util.List;
//import java.util.stream.Collectors;
//import java.util.stream.IntStream;
//
//class Solution {
//    public int solution(int k, int m, int[] score) {
//        if (score.length < m) {
//            return 0;
//        }
//        int numSaleApple = m * (score.length / m);
//        List<Integer> collect = Arrays.stream(score)
//                .boxed()
//                .sorted(Collections.reverseOrder())
//                .limit(numSaleApple)
//                .collect(Collectors.toList());
//        return IntStream.range(0, collect.size())
//                .filter(i -> i % m == m - 1)
//                .map(collect::get)
//                .reduce(Integer::sum)
//                .getAsInt() * m;
//    }
//}

class main{

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr ={1, 2, 3, 1, 2, 3, 1};
        System.out.println("sol = " + sol.solution(3,4,arr));
    }

}
