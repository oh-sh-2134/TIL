alpa = input()
alpalist = ['ABC','DEF','GHI','JKL','MNO','PQRS','TUV','WXYZ'] # 다이얼에서 같은번호끼리 묶음
cnt = int()
for i in alpalist : #리스트에서 각 번호씩
    for k in i : # 알파벳을 체크해서
        for j in alpa : #input값도 알파벳 단위로 쪼개어서
            if k == j : #input값에서 동일한게 있으면
                cnt += alpalist.index(i) + 3
print(cnt)
#https://www.acmicpc.net/problem/5622
#다이얼 숫자별로 list를 만들어서 각 원소가 있을때 카운팅 하는방식