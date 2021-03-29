#정규표현식
#[abc] -> 문자열중 abc중 하나라도 포함하면 매칭 [a-c]로 표현가능
#Dot(.) a.b -> a와 b사이에 문자가 있는것은 매칭됨 사이에 아무것도 없는 ab는 매칭안됨
#반복 * ca*t -> ct사이에 a가 몇번이 반복되든 매칭이됨 0번 반복인 ct일때는 매칭 안됨
#ca{2}t -> caat만 매칭됨 ca{2,5} => caat, caaaaat 
#ab?c ?는 {0,1} 가능

#match
"""
import re
p = re.compile ('[a-z]+') #a부터z까지의 문자열이 한번이상 반복이되는 것
m = p.match('python') # p의 조건에 맞아야 함
m = p.search('3  python') # 첫번째가 일치하지 않아도 알파벳이 있다면 매칭해 줌
m = p.findall('life is too short') #매칭이 가능한 단어별로 리스트를 만들어줌
m = p.finditer('life is too short') # for문을 통해 확인하면 매치 객체를 반복가능한 형태로 리턴
for r in m :
    print(r)
print(m)
print(3) #3은 알파벳이 아니라 none 출력
m = p.match('python') 
print(m.group()) # match 객체의 문자열
print(m.start()) # match 객체의 첫번째 위치
print(m.end())  # match 객체의 마지막 위치
print(m.span()) # match 객체의 위치를 튜플 형태로 줌
"""
#DOTALL, S(약어)
"""
import re
p = re.compile('a.b',re.DOTALL)
m = p.match('a\nb') #줄바꿈있어도 매칭됨
print(m)
"""
# IGNORECASE , I(약어)
"""
import re
p = re.compile('[a-z]')
m = p.match('python')
m = p.match('PYTHON') # 대소문자 무시하고 매칭
"""
# MULTILINE , M
"""
import re
p = re.compile("^python\s\w+", re.M) #^는 맨처음을 의미 맨처음에 python이 나오고 한칸 띄고 글자
data = """""" python one 
life is too short
python two
""""""
#python one만 나옴
# ,re.M 옵션을 주면 python two도 나옴 줄바꿈 했을때 첫번째를 찾음
print(p.findall(data))
"""
#메타문자 |
"""
import re
p = re.compile('Crow|Servo')
m = p.match('CrowHello') 
print(m) #CrowHello 출력
"""
#메타문자 ^
"""
import re
p = re.search('^Life', 'Life is too short') # 맨앞에 Life를 찾음 바로 찾기도 가능
print(p)
"""
#메타문자 $
"""
import re
p = re.search('short$' , 'Life is too short') # 맨끝에 있는걸 찾음
"""
#메타문자 \b
"""
import re
p = re.compile(r'\bclass\b')
print(.p.search('no class at all')) #\b는 공백을 의미 양쪽에 공백인 class 찾음
"""
#그루핑 ()
"""
import re
p = re.compile('(ABC)+') #ABC가 반복되는 걸 찾음
m = p.search('ABCABCABC DKAKSE')
print(m)
#그루핑된 문자열에 이름 붙이기 ?P<name>
p = re.compile(r"(?P<name>\w+)\s+((\d+)[-]\d+[-]\d+)") # +에 띄워쓰기하면안됨
m = p.search("oh 010-1234-1234")
print(m.group("name"))
"""
#전방탐색 : 긍정형 (?=)
"""
import re
p = re.compile(".+:") # http: 조건이 포함됨 # re.complile(".(?=:)") => http 결과에는 조건이 포함 안됨
m = p.search("http://google.com")
print(m.group)
"""
#전방탐색 (?!) 포함하지 않는것을 써야함
"""
import re
p = re.compile(".*[.](?!bat$).*$",re.M) # .* 문자열 뒤에 [.]이 나오고 맨뒤에 확장자명이
l = p.findall("""
"""
autoexe.exe
autoexe.bat
autoexe.jpg
"""
""")
# exe, jpg만 나옴
print(l)
"""
#문자열 바꾸기 sub
"""
import re 
p = re.compile('(blue|white|red)') #정규 표현식안에 있는 것이 매칭되면
p.sub('colour', 'blue socks and red shose') # colour으로 바꾸게 함
"""
#Greedy vs Non-Greedy
"""
import re
s = '<html><head><title>Title</title>'
print(re.match('<.*>',s).group()) #Greedy < > 안에 있는 것이 출력됨 <html><head><title>Title</title>
print(re.match('<.*?>',s).group()) #Non-Greedy ?가 들어가면 최소한으로 나옴 <html>
"""