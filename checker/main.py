import os
import sys

# 编译

os.system("g++ -o testing " + sys.argv[1])
os.system("g++ -o std " + sys.argv[2])

# 构造输入数据
os.system('python ' + sys.argv[3])


os.system('./testing < data.in > data.out')
os.system('./std < data.in > data.ans')


f1 = open('data.out', 'r')
f2 = open('data.ans', 'r')

print(f1.read())
print(f2.read())
