#튜플 : 리스트랑 비슷하지만 수정 할 수 없고 []가 아닌 ()을 사용
"""
t1 = (1,2,'a','b')
t2 = (3,4)
a = t1+ t2
#del t1[0] 불가능 튜플은 삭제 할 수없음
# t1[0] = 3 불가능 튜플은 내용물 변경(인덱싱) 불가능
#print(t1[0:2]) # 슬라이싱 해서 볼 수 있음
#print(t1 + t2) # 더하기 가능 => 새로운 튜플로 만든느 것
#print(t1*3) # 곱하기 가능
print(a)
a , b = ('python' , 'c++')
a와 b의 튜플에 각각 값을 넣어줌 
a = b = 'hellow'
a와 b에 동일 index를 넣어 줌
a = 3
b = 5
a, b = b, a
a와 b의 값을 바꾸어줌
"""



# 딕셔너리 : key를 이용하여 value을 찾을때 사용 , 연관배열 , 해쉬 , api에 자주 사용됨
"""
osh = {'age' : 26}
osh['live'] = "dj"

#del osh['live']
print(osh)
print(osh.keys()) #dict_keys라는 리스트에 key 값들만 뽑아짐
print(osh.values()) # 마찬가지
print(osh.items()) # 딕셔너리 전체
#osh.clear # 딕셔너리 모두 삭제
print('age' in osh) # osh 딕셔너리에 'age' 키값이 있는지 체크 후 불형으로 반환

a = {1:'a', 1  : 'b'} # 같은 키를 가지면 안됨
print (a[1]) 
"""

#집합 : 중복된 요소를 가질 수 없음 , 순서가 없음(인덱싱이 안됨)
"""
s1 = set([1,2,3]) # set으로 배열을 감싸서 사용
s1 = {1,2,3}
print (type(s1))

l = [1,2,2,3,4,4]
newList = list(set(l)) ##l 배열을 집합으로 중복을 제거하고 리스트로 만듬 -> 데이터 중복 방지
print (newList)

s2 = set("hellow word") #string 으로 넣어도 중복을 제거하고 집합화 시킴
print(s2)

s1 = set([1,2,3,4,5,6,7])
s2 = set([4,5,6,7,8,9,10])
print(s1.intersection(s2)) # == print(s1 & s2) 교집합 구하는 방법
print(s1 | s2) # == print(s1.union(s2)) 합집합 구하는 방법
print(s1 - s2) # == priint(s1.difference(s2)) 차집합 구하는 방법
s1.add(7) # 원소 추가
print(s1)
s1.update([11,12,31]) #많은 원소들을 추가할때
print(s1)
b=True
"""
#if문
"""
if b : print(s1) #if 문 , 문자열이나 다른 자료형에서도 값이 있으면 참 값을 가짐
"""
#while 문
"""
a = [1,2,3,4,5]

while a : 
    a.pop()
    print(a)
"""
#변수
#pythontutor.com 으로 가면 자료형이 어떻게 메모리에 저장되는지 알 수 있음
"""
a = [1,2,3,4,5]
b= a # b에 a 주소를 주기 때문에
a[1] = 4 # a[1]을 4로 바꾸면 b를 찍을때도 값이 바껴있음
print(a)
print(b)
print(id(a)) #a의 주소값을 찍는것
print(a is b) # a와 b는 같은 주소값을 가지는지 bool 타입으로 반환

b = a[:] #a[:]를 하면 a에 있는 값을 슬라이싱하여 새로운 메모리에 a와 같은 리스트 값을 가진 b를 생성 
print(a)
print(b)
print(id(a))
print(a is b)

from copy import copy #copy라는 모듈 라이브러리을 이용하여 copy를 사용 
b = copy(a) # 주소값을 공유하지 않는 변수 생성
print(a)
print(b)
print(id(a))
print(a is b)


lmmutable 변하지 않는 자료형(정수, 실수, 문자열, 튜플)
a=1
def vartest(a) :
    a = a+1   # 지역변수
vartest(a)    #새로운 변수 a를 선언하여 전역변수 a와 1을 더한 새로운 변수를 만듬
print(a)
# a는 변하지 않고 1이 나옴

Mutable(튜플, 딕셔너리, 집합)
b = [1,2,3] #전역변수
def = vartest2(b) : 
    b = b.append(4) #지역변수
vartest2(b)         #지역변수임에도 4라는 변수의 주소값을 추가 해주기 때문에 추가가됨
print(b)
# 리스트에 4가 추가됨
"""