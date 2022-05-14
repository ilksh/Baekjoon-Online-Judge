def eratosthenes(max_n):
    num = [False, False] + [True] * (max_n - 1)
    primes = []

    for i in range(2, max_n + 1):
        if num[i]:
            primes.append(i)
            # remove all of i's multiplies
            # because they are not prime number
            for j in range(i * 2, max_n + 1, i):
                num[j] = False

    return primes


n = int(input())
prime_num = eratosthenes(n)

ans = []


def factorization(target):
    for prime in prime_num:
        if target % prime == 0:
            ans.append(prime)
            return factorization(target // prime)


factorization(n)

for data in ans:
    print(data)
