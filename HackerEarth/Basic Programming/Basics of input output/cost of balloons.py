TestCases = int(input())
swapKey = 1
for i in range(TestCases):
    costOfBoll0ons = [int(x) for x in input().split()]
    if swapKey % 2 == 0:
        temp = costOfBoll0ons[0]
        costOfBoll0ons[0] = costOfBoll0ons[1]
        costOfBoll0ons[1] = temp
    participants = int(input())
    answers = []
    money = 0
 
    for j in range(participants):
        answers.append([int(z) for z in input().split()])
 
    for k in range(len(answers)):
        for l in range(len(answers[k])):
            if l == 0 and answers[k][l] != 0:
                money += costOfBoll0ons[0]
            elif l == 1 and answers[k][l] != 0:
                money += costOfBoll0ons[1]
    swapKey += 1
 
    print(money)
