for t in range(int(input())):
    s = input()
    use_power = False
    ans = 0
    for i in s:
        if i == "0" and not use_power:
            use_power = True
            ans += 1
        elif i == "1" and use_power:
            use_power = False
            ans += 1
    print(ans)
