t = int(input())
for i in range(t):
    n = int(input())
    hungers = [0]*n
    hungers = input().split()
    for j in range(n):
        hungers[j] = int(hungers[j])
    if len(hungers) > 1:
        if hungers[0] > hungers[1]:
            print(-1)
            continue
    if len(hungers) == 2:
        if hungers[0] != hungers[1]:
            print(-1)
            continue
        else:
            print(0)
            continue
    #try to make next one equal to one before with pair feeding
    corn = 0
    for j in range(n-2):
        if hungers[j] > hungers[j+1]:
            continue
        diff = (hungers[j+1]-hungers[j])
        corn += 2*diff
        hungers[j+1] -= diff
        hungers[j+2] -= diff
    #reverse of previous loop
    for j in range(n-1, 1, -1):
        if hungers[j-1] < 0 or hungers[j] < 0:
            corn = -1
            break
        diff = (hungers[j-1]-hungers[j])
        corn += 2*diff
        hungers[j-1] -= diff
        hungers[j-2] -= diff
    print(corn)
