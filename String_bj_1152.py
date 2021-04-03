test_str = input().split(" ") #input받을때 공백을 기준으로 짤라서 리스트 처리
test_str = [item for item in test_str if item != ""] #각 리스트에서 공백을 제외
print(len(test_str))
#https://www.acmicpc.net/problem/1152
#리스트 컴프리헨션 사용했음
#list안에서 for문과 if가 사용이 가능한게 너무 편함