def two_sum(numbers, target):
    left, right = 0, len(numbers) - 1
    store_index = []
    for i in range(len(numbers)):
        store_index.append([numbers[i], i])
    store_index.sort()
    while left < right:
        val = store_index[left][0] + store_index[right][0]
        if val == target:
            return [store_index[left][1], store_index[right][1]]
        elif val > target:
            right -= 1
        else: left += 1
    return [-1, -1]
