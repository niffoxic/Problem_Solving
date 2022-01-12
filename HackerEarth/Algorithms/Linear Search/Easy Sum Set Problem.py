setA_number = int(input())
setA_elements = [int(x) for x in input().split()]
setC_number = int(input())
setC_elements = [int(x) for x in input().split()]
setB_elements = []
if setA_elements[setA_number - 1] > setC_elements[setC_number - 1]:
    set_range = setA_elements[setA_number - 1] - setC_elements[setC_number - 1] + 1
 
else:
    set_range = setC_elements[setC_number - 1] - setA_elements[setA_number - 1] + 1
 
ranges_are = list(range(1, set_range))
 
for i in range(len(ranges_are)):
    for j in setA_elements:
        if ranges_are[i] + j not in setC_elements:
            ranges_are[i] = "x"
            break
 
for i in range(len(ranges_are)):
    if ranges_are[i] != "x":
        print(ranges_are[i], end=" ")
