n = int(input())
pos = [0]*n
maxX = 0
maxY = 0
for i in range(n):
    x, y = input().split(); x, y = int(x), int(y)
    pos[i] = [x, y]
    if x > maxX:
        maxX = x
    if y > maxY:
        maxY = y
cows = [0]*(maxX+1)
for i in range(maxX+1):
    line = [0]*(maxY+1)
    cows[i] = line
comfyCows = 0
dr = [0, 1, 0, -1, 0]
dc = [0, 0, 1, 0, -1]
for i in range(n):
    X = pos[i][0]
    Y = pos[i][1]
    cows[X][Y] = 1
    for j in range(5):
        x = X+dr[j]
        y = Y+dc[j]
        if x > maxX or y > maxY or x < 0 or y < 0 or cows[x][y] == 0:
            continue
        count = 0
        if x > 0 and cows[x-1][y] == 1:
            count += 1
        if y > 0 and cows[x][y-1] == 1:
            count += 1
        if x < maxX and cows[x+1][y] == 1:
            count += 1
        if y < maxY and cows[x][y+1] == 1:
            count += 1
        if count == 3:
            comfyCows += 1
        elif count == 4 and (x != X or y != Y):
            comfyCows -= 1
    print(comfyCows)
