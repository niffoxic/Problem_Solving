def palindrome(str):
    last = len(str) - 1
    for i in range(len(str)):
        if str[i] != str[last]:
            return print("NO")
        elif i == last:
            return print("YES")
        last -= 1
    else:
        return print("YES")
 
 
string = input()
palindrome(string)
