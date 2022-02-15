n, m, a, b = map(int, input().split());print(min(b * (n // m) + min(a * (n % m), b), n * a))
