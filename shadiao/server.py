#!/home/rdstihz/.conda/envs/shadiao/bin/python
import socket

from sympy import *
import time

def returnDiff(info, c, addr):
    f = sympify(info[1])
    vars = []
    vars_lst = info[2].split(" ")

    for t in vars_lst:
        vars.append(symbols(t))

    # 求导
    res = ""
    for x in vars:
        f_x = Derivative(f, x)
        eq = Eq(f_x, simplify(f_x.doit()))
        res += ('$$' + latex(eq) + '$$\n')
    c.send(res.encode())
    print(time.strftime("[%Y-%m-%d %H:%M:%S] ",time.localtime()) + 'Sent information to' , addr)
    print("\tInformation:\n\t\t",res)
    


def returnInte(info, c, addr):
    f = sympify(info[1])
    vars = []
    vars_lst = info[2].split(" ")

    for t in vars_lst:
        vars.append(symbols(t))

    # 求不定积分
    res = ""
    for x in vars:
        f_x = Integral(f, x)
        eq = Eq(f_x, simplify(f_x.doit()))
        res += ('$$' + latex(eq) + '+C$$\n')
    c.send(res.encode())
    print(time.strftime("[%Y-%m-%d %H:%M:%S] ",time.localtime()) + 'Sent information to' , addr)
    print("\tInformation:\n\t\t",res)


s = socket.socket()
host = socket.gethostname()
port = 31453
s.bind(("0.0.0.0", port))

s.listen(5)


count = 0

while True:
    print('------------------------------')
    c, addr = s.accept()
    print(time.strftime("[%Y-%m-%d %H:%M:%S] ",time.localtime()) + 'Got connection from' , addr)
    
    # 接收信息
    info = c.recv(8192).decode().split('\n')
    print(time.strftime("[%Y-%m-%d %H:%M:%S] ",time.localtime()) + 'Received information from' , addr)
    print("\tInformation:")
    for line in info:
        print('\t\t' + line)

    # 求导
    if info[0] == 'diff':
        try:
            returnDiff(info, c, addr)
        except:
            c.send("Wrong Input\n".encode())

            print(time.strftime("[%Y-%m-%d %H:%M:%S] ",time.localtime()) + 'Sent information to' , addr)
            print("\tInformation:\n\t\tWrong Input")

    elif info[0] == 'inte':
        try:
            returnInte(info, c, addr)
        except:
            c.send("Wrong Input\n".encode())

            print(time.strftime("[%Y-%m-%d %H:%M:%S] ",time.localtime()) + 'Sent information to' , addr)
            print("\tInformation:\n\t\tWrong Input")
    
    else:
        c.send("Wrong Input\n".encode())

        print(time.strftime("[%Y-%m-%d %H:%M:%S] ",time.localtime()) + 'Sent information to' , addr)
        print("\tInformation:\n\t\tWrong Input")

    c.send(time.strftime("现在是%H点%M分，闫磊，我们的神!!!\n").encode())
    c.close()

    count += 1
    print(count)

    
    print(time.strftime("[%Y-%m-%d %H:%M:%S] ",time.localtime()) + 'Loss connection with' , addr)
    
    print('------------------------------')
