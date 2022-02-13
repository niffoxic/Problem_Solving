def factorials(n):
    result = 1
    if n <= 1:
        return result
    else:
        for i in range(n):
            i += 1
            result *= i
        return result
number = int(input())
print(factorials(number))
