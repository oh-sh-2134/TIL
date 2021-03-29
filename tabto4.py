#파일을 열어서 탭을 4*공백으로 수정하는 파일
import sys

src = sys.argv[1]
dis = sys.argv[2]

f = open(src)
tab_content = f.read()
f.close()

space_content = tab_content.replace("\t", " "*4)

f = open(dis, "w")
f.write(space_content)
f.close()
