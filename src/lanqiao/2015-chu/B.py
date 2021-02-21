import sys


days = [0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

for line in sys.stdin:
    a, b, c, d = map(int, line.split())

    while d:
        c += 1
        d -= 1

        if b != 2:
            if c > days[b]:
                b = b + 1
                c = 1
        else:
            t = 28
            if a % 400 == 0 or (a % 100 != 0 and a % 4 == 0):
                t = 29
            if c > t:
                b = b + 1
                c = 1
        if b > 12:
            a = a + 1
            b = 1
        
    print("%04d-%02d-%02d" % (a,b,c))

