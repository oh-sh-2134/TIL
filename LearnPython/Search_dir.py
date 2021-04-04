#특정 경로에서 확장자명으로 파일 검색
import os #운영체제관련 함수
def serch(dirname):
    try :
        filenames = os.listdir(dirname) # 경로안에 있는 파일을 리스트로 반환
        for filename in filenames: 
            full_filename = os.path.join(dirname, filename) # 파일 경로를 만들어줌
            if os.path.isdir(full_filename) : #경로안의 파일이 디렉토리라면
                serch(full_filename) # 재귀
            else :
                ext = os.path.splitext(full_filename)[-1] 
#splitext는 확장자명과 파일명을 나누어서 출력함 확장자명을 선택하려면 뒤에있는 파일을 선택하는 옵션-1
                if ext == ".py" :                 #확장자명이 .py면 
                    print(full_filename)            #출력
    except PermissionError :
        pass

serch("C:/")