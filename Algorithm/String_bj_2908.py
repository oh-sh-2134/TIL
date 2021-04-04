num1, num2 = input().split()
compare = lambda x,y : x if x>y else y

num1 = int(num1[::-1])
num2 = int(num2[::-1])
result = compare(num2,num1)
print(result)
#https://www.acmicpc.net/problem/2908
#람다를 활용해서 풀었음