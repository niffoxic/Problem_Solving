length_of_array = int(input())
array_list = input().split()
last_digi = ""
for i in range(length_of_array):
    last_digi += array_list[i][len(array_list[i]) - 1]
 
if int(last_digi) % 10 == 0:
    print("Yes")
else:
    print("No")
