test_str = input()
test_str = test_str.replace("c=","#")
test_str = test_str.replace("c-","#")
test_str = test_str.replace("dz=","#")
test_str = test_str.replace("d-","#")
test_str = test_str.replace("lj","#")
test_str = test_str.replace("nj","#")
test_str = test_str.replace("s=","#")
test_str = test_str.replace("z=","#")
print(len(test_str))
#https://www.acmicpc.net/problem/2941
#replace 함수로 크로아티아 글자를 # 으로 바꾸고 문자열을 카운팅만 해주면 됨