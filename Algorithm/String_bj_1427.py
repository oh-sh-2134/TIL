num = input()
num = [int(n) for n in num]
num = sorted(num, reverse=True)
for n in num :
    print(n,end="")
#https://www.acmicpc.net/problem/1427
#파이썬으로 풀면 쉽게풀림...