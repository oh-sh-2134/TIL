#조건문
"""
money = False
card = True
if money or card :  # False or True /  and도 마찬가지로 money and card로 하면 됨
    print("택시 탄다")
else :
    print("걸어간다")


a = [1,2,3,4,5,6,[1,2]]

if [1,2] in a : 
    print("있음")


if 1 and 22 in a : 
    print("있음")
elif 1 in a :
    print("1만 있음")
elif 22 in a :
    print("22만 있음")
else :
    print("아무것도 없음")

#조건부 표현식 성공시 메시지를 먼저 선언하고 실패시 false를 바로 출력하도록 1줄로 깔끔\
# 3항 연산자를 python으로 사용한것  score>=60 ? "succerss" : "false" 와 비슷
socore = 70
message = "success" if socore >= 60 else "false" 

a=0
while a<10 : 
    if a==3 :
        a+=1
        continue
    if a==7 : 
        break
    print(a)
    a += 1
"""

#반복문
"""
cont = ['one', 'two']
for i in cont :
    print(i)

addidx = [(1,2) , (3,4) , (4,5)]
for(first, last) in addidx :
    print(first + last)

# c++ 처럼 1에서 10미만까지
for i in range(1,10) :
    print("cont : ")
    print(i)
    print("\n")
"""