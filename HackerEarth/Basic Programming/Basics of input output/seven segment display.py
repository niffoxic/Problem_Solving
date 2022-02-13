segments = {0: 6,
            1: 2,
            2: 5,
            3: 5,
            4: 4,
            5: 5,
            6: 6,
            7: 3,
            8: 7,
            9: 6}
 
for _ in range(int(input())):
    number = input()
    here = 0
    for i in range(len(number)):
        here += segments[int(number[i])]
    if here % 2 == 0:
        print("1" * int(here / 2))
    else:
        print("7" * 1 + ("1" * (abs(here//2) - 1)))
 
