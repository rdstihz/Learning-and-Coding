T = int(input())

while T:
    T -= 1
    n,k = map(int,input().split())
    print(pow(n, k, 1000000007))