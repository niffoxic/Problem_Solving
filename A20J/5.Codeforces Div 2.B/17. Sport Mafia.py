n, k = map(int, input().split())


def get_sum(val):
    return (val * (val + 1)) >> 1


def bin_search():
    left, right = 0, n
    while left <= right:
        mid = (left + right) // 2
        if mid + k == get_sum(n - mid):
            return mid
        elif mid + k > get_sum(n - mid):
            right = mid - 1
        else:
            left = mid + 1
    return -1


print(bin_search())
