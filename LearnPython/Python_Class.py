## Class
"""
class Calculator :   #첫글자는 대문자
    def __init__(self):   #생성자
        self.result = 0

    def add(self, num) :
        self.result +=num
        return self.result

cal1 = Calculator()
cal2 = Calculator()

print(cal1.add(1)) # self가 cal1이고 num이 1
print(cal1.add(2)) # self가 cal1이고 num이 2 그래서 self.result 3
"""
"""
class FourCal :
    def setdata (self, first, second):
        self.first = first
        self.second = second

    def add(self) : 
        self.result = self.first + self.second
        return self.result
    def div(self):
        self.result = self.first / self.second
        return self.result
a= FourCal()
print(type(a))

ad = FourCal()
ad.setdata(23,44)
print(ad.add())

class MoreFourCla(FourCal): #FourCal 상속하는 방법
    def div(self):
        if self.second == 0 :
            return "0으로 나눌 수 없음"
        else :
            return self.first /self.second
    pass
newadd = MoreFourCla()
newadd.setdata(4,7)
print(newadd.add())
newadd.setdata(23,0)
print(newadd.div())
"""
# 모듈
#form mod1 improt add     - mod1파일에서 add변수만 가져옴
#mod1.py가 같은 경로에 있다고 하면
"""
def add(a,b) :
    return a+b
def sub(a,b) : 
    return a-b

if __name__ == "__main__" : #mod1파일에서 실행해야함 즉, mod1파일이 main파일이여야 실행하는 것
    print((add(1,2)) #print문은 mod1파일이 실행이 되어야 print함
"""
# 같은 경로에 있지 않으면 sys에 경로를 넣어줘야함
"""
import sys
sys.path.append("C: \\ PythonTest \\ subFolder")
import mod1
print(mod1.add(1,2))
"""
#패키지
"""
import game.suond.echo #game 파일안에 sund 파일안에 echo 파일을 불러옴
echo_test() #echo 패키지안의 echo_test() 함수만 가져옴
e() #에코를 e()로 바꾸어 사용
"""

#에러처리
try :
    4/0
except ZeroDivisionError as e:
    print(e)

print("에러처리 성공")

try :
    f=open('none', 'r')
except FileNotFoundError as e:
    print(str(e))
else : # try가 성공했을때
    data = f.read()
    print(data)
    f.close
finally : #예외처리에 성공하든 안하든 무조건 실행하는 것 ( 파일을 열었으면 무조건 닫아야 함 )
    f.close

try :
    f = open("없는 파일",'r')
except FileNotFoundError :
    pass