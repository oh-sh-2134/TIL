import re
def solution(expression):
    answer = 0
    arr = ["*+-", "*-+" , "+*-", "+-*", "-+*" , "-*+"]
    for i in range(6):
        oper = re.findall("[+*-]+", expression)
        num  = re.findall("[0-9]+", expression)
        for j in range(3):
            k = 0
            while k<len(oper):
                if oper[k] == arr[i][j]:
                    num[k] = str(eval(num[k] + oper[k] + num[k+1]))
                    del num[k+1]
                    del oper[k]
                else :
                    k +=1
        answer = max(answer,abs(int(num[0])))                
    return answer

sol = solution("100-200*300-500+20")
print(sol)