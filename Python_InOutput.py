# 함수
"""
def sum(a,b) : 
    result = a+ b
    return result

print(sum(1,2))

def sum_many(*arr): #d여러개의 값들을 받을 수 있는 것
    sum=0
    for i in arr:
        sum = sum +i
    return sum
print(sum_many(3,5,6,7,8))

def print_name(**kwargs) : # **은 딕셔너리 타입을 받아서 계산함
    for k in kwargs.keys() :
        if(k == "name") :
            print("이름은 : " + k)
print(print_name(name = "osh", age = 26))


def sum_and_mul(a,b) : #튜플형태로 받음
    return a+b, a*b, a-b

print(sum_and_mul(1,2)[1])

def myself(name, old, man = True) : #man을 default값으로 True로 줌
    print("나의 이름은 : " + name)
    print("나의 나이는 : %d" %old)
    if man :
         print("나의 성별은 남자")
    else :
        print("나의 성별은 여자")

myself("오승현", 26)

#lambda 함수를 간단하게 선언하는 방법 
add = lambda a,b : a+b
print(add(1,2))
mylist  = [lambda a,b:a+b , lambda a,b:a-b]
#리스트 안에도 람다를 이용해서 함수처럼 만들 수 있음
print(mylist[0](1,2))
"""

#표준입력
"""
a = input("입력하시오 : ")
print(a)
"""
#print
"""
print("life" "is" " too short") # 단어 붙여서 출력
print("life", "is", " too short") # ,를 사용하면 띄워쓰기

for i in range(1 ,5) :
    print(i , end=" ") # ,end = 자동 개행되지 않게 막아주고 뒤에 문자를 하나 더 추가 할 수 있음
"""
#file
"""
f = open("새파일.txt",'w', encoding="UTF-8") 
for i in range(1,11) :
    data = "%d번째 줄입니다.\n" %i
    f.write(data)
f.close()

f = open("새파일.txt",'r', encoding="UTF-8")
while True:
    line = f.readline()
#   line = f.readlines() 전체를 모두 가져옴
    if not line : break
    print(line)
f.close()

with open("foo.txt", "w") as f: #f라는 변수에 저장하고 whit 문이 끝나면 자동 close
    f.write("asdafasfas")
"""