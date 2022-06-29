mod = int(1e9) + 7

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    q = int(input())
    left = list(map(int, input().split()))
    right = list(map(int, input().split()))
    prefix = [0]
    for i in arr:
        prefix.append(i + prefix[-1])
    # print(prefix)
    # print(left)
    # print(right)

    for i in range(q):
        middle_weight = right[i] - left[i] + 1
        li = left[i] % n
        ri = right[i] % n
        li = li if li else n
        ri = ri if ri else n

        left_hand = prefix[-1] - prefix[li - 1]
        middle_weight -= (n - li) + 1
        right_hand = prefix[ri]
        middle_weight -= ri
        print((left_hand + (middle_weight // n) * prefix[-1] + right_hand) % mod, end=" ")
    print()
