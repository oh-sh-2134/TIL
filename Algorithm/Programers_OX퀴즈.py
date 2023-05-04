def solution(a):
    b = -1
    answer = []
    n =""
    while 1:
        if b == len(a)-1:
            break
        b=b+1
        t = a[b].split()
        print(t)
        if t[1] == '+':
            if int(t[0]) + int(t[2]) == int(t[4]):
                answer.append("O")
            if int(t[0]) + int(t[2]) != int(t[4]):
                answer.append("X")
        if t[1] == '-':
            if int(t[0]) - int(t[2]) == int(t[4]):
                answer.append("O")
            if int(t[0]) - int(t[2]) != int(t[4]):
                answer.append("X")
    return answer
    #https://school.programmers.co.kr/learn/courses/30/lessons/120907
