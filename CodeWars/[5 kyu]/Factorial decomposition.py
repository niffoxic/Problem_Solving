raw_primes = [True] * int(1e5)
primes = []
for i in range(2, int(1e5)):
    if raw_primes[i]:
        primes.append(i)
        for j in range(i * i, int(1e5), i):
            raw_primes[j] = False


def decomp(n):
    val = 1
    for i in range(1, n + 1):
        val *= i
    index = 0
    res = ""
    while val > 1:
        counts = 0
        while val % primes[index] == 0:
            counts += 1
            val //= primes[index]
        if counts == 0:
            index += 1
            continue
        if counts == 1:
            res += str(primes[index]) + " * "
        else:
            res += str(primes[index]) + "^" + str(counts) + " * "
        index += 1
    return res[:-3]


