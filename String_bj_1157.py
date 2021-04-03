word = input().upper() #대문자로 받음
word_list = list(set(word)) #단어에서 중복을 제거하고 알파벳별로 튜플 만듬
cnt = []
for i in word_list : #알파벳별 체크
    count = word.count(i)  # 단어에서 알파벳이 몇번식 사용되었는지 카운트
    cnt.append(count) # 각 카운트별로 저장하게되면 word_list의 알파벳과 cnt의 숫자가 1:1 매칭이됨
if cnt.count(max(cnt)): #가장 큰 숫자가 두개 이상일때
    print("?") 
else :
    print(word_list[cnt.index(max(cnt))].upper()) #가장큰 수의 index값을 word_list로 넘겨서 출력
#https://www.acmicpc.net/problem/1157
#입력받은 단어에서 중복을 제거하고 각 문자가 몇번 사용 되었는지 체크해서 가장 많이 사용된 단어 출력