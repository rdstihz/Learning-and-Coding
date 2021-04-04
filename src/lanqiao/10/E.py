
def exgcd(a, b):
    if b == 0:
        return 1,0,a
    else:
        y,x,d = exgcd(b, a % b)
        y -= (a // b) * x
        return x,y,d

n = 1001733993063167141
d = 212353
p = 891234941
q = 1123984201

phi = (p - 1) * (q - 1)

e, y, t = exgcd(d, phi)
e = (e % phi + phi) % phi
print(d, e)

print(pow(579706994112328949,212353,1001733993063167141))