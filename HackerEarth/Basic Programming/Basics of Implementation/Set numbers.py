for _ in range(int(input())):
    number = int(input())
    binary_form = len(bin(number)[2:])
    if bin(number)[2:].count("0") == 0:
        print(number)
    else:
        print(int(2**(binary_form - 1) - 1))
