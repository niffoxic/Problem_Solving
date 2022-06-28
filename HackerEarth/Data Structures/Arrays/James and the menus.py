n, m = map(int, input().split())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))
res = dict()
res_max = 0
res_id = -1
for j in range(m):
    current_max = -1
    max_vals = []
    for i in range(n):
        if current_max == arr[i][j]:
            max_vals.append(i)
        elif current_max < arr[i][j]:
            max_vals.clear()
            max_vals.append(i)
            current_max = arr[i][j]
    for i in max_vals:
        res[i] = 1 if i not in res else res[i] + 1
        if res[i] > res_max:
            res_max = res[i]
            res_id = i
avg = sum(arr[res_id])
for key, val in res.items():
    if val == res_max:
        here = sum(arr[key])
        if avg < here:
            res_id = key
            avg = here
print(res_id + 1)
