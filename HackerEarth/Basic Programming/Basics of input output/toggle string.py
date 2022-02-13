string = input()
newString = ""
for i in range(len(string)):
    if string[i] == string[i].upper():
        newString += string[i].lower()
    else:
        newString += string[i].upper()
print(newString)
