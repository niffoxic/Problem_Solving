n = input()
if (int(n[0])+int(n[1]))%2 == 0 and n[2] not in 'AEIOUY' and (int(n[3])+int(n[4]))%2 == 0 and (int(n[4])+int(n[5]))%2 == 0 and (int(n[7])+int(n[8]))%2 == 0 and n[6] == '-':
    print('valid')
else:
    print('invalid')
