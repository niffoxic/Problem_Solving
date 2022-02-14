for x in range(int(input())):
 
    candy, number = [int(y) for y in input().split()]
 
    a = number*(number - 1) // 2
    b = (candy - a) // number
 
    if b < 1:
        print(candy)
    else:
        ans = candy - (b*number + a)
        print(ans)
