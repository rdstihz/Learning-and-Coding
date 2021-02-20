
def exgcd(a,b,x,y):
    if b == 0:
        x[0] = 1
        y[0] = 0
        return a
    else:
        d = exgcd(b,a % b, y,x)
        y[0] -= x[0] * (a // b)
        return d

s = input().split()
a = int(s[0])
b = int(s[1])

x = [0]
y = [0]

exgcd(a,b,x,y)
x[0] = (x[0] % b + b) % b
print(x[0])
