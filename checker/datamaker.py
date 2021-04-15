from random import randint

primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53]

T = 2
k = primes[randint(0, len(primes) - 1 )]

date = open("data.in", "w")

date.write('{} {}\n'.format(T,k))

for i in range(T):
    n = randint(1, 50)
    m = randint(1,50)
    date.write('{} {}\n'.format(n,m))

date.close()

