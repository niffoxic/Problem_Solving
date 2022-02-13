total_numbers = int(input())
total_elements = [int(x) for x in input().split()]
product = 1
supp = 1
for i in range(total_numbers):
    product = total_elements[i] * supp
    supp = product % (10 ** 9 + 7)
 
print(supp)
