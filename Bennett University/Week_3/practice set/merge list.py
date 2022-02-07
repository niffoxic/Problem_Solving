for _ in range(int(input())):
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))
    merge = []
    i = j = 0
    while i < n and j < m:
        if arr[i] <= arr2[j]:
            merge += [arr[i]]
            i += 1
        else:
            merge += [arr2[j]]
            j += 1
    for k in range(i, n):
        merge += [arr[k]]
    for k in range(j, m):
        merge += [arr2[k]]
    for i in merge:
        print(i, end=" ")
