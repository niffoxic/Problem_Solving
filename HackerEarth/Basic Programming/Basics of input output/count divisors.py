l, r, k = (int(x) for x in input().split())
def divisors(low, right, kn):
 
    val = 0
    for i in range(l, r + 1):
        if i % k == 0:
            val += 1
    return val
here = divisors(l, r, k)
print(here)
