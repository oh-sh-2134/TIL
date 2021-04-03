num = int(input())
result = str()
for i in range(num) :
    test_cnt, test_str = input().split()
    test_time = int(test_cnt)
    for j in test_str :
        result  +=  j*int(test_cnt)
    print(result)
    result = str()
#https://www.acmicpc.net/problem/2675
#파이썬을 익히기 위해서 이전에 풀었던 문제들을 파이썬으로 다시 풀어 봄