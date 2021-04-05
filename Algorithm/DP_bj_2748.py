n = int(input())
fibo = []
num = int(0)
for i in range(n+1):
    if i == 0:
        num = 0
    elif i <= 2: #1,2일 경우
        num = 1
    else :
        num = fibo[-1] + fibo[-2] #DP
    fibo.append(num)
print(fibo[-1])
#https://www.acmicpc.net/problem/2748
#fibo 리스트에 0부터 n까지(n+1을 해야 n까지 값이 채워짐) 피보나치 수열들을 채워나감