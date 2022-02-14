for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    even_counts = 0
    odd_counts = 0
    for i in arr:
        if i % 2:
            odd_counts += 1
        else:
            even_counts += 1
    print(min(odd_counts, even_counts))
