for _ in range(int(input())):
    strings = input()
    if strings == strings[::-1]:
        print("-1")
    else:
        print("".join(sorted(strings)))
