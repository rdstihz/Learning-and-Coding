def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)
    

print(gcd(1951, 2021))
a = 1952
b = 2021
print(a * b - a - b)