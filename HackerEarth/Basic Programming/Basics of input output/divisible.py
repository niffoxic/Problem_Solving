number = ""
size_of_arr = int(input())
array = [x for x in input().split()]
half = size_of_arr // 2
for i in range(size_of_arr):
    if i < half:
        number += array[i][0]
    else:
        number += array[i][len(array[i]) - 1]
if int(number) % 11 == 0:
    print("OUI")
else:
    print("NON")
