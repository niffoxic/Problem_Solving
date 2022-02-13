grids_number = int(input())
village = input()
if "." in village:
    if "HH" in village:
        print("NO")
    else:
        print("YES")
        print(village.replace(".", "B"))
elif grids_number == 1 and "H" in village:
    print("YES")
    print("H")
elif grids_number == 1 and "." in village:
    print("NO")
else:
    print("NO")
