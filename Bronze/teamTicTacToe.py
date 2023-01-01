inpu = open("tttt.in", "r")
board = [0]*3
dict = {}
for i in range(3):
    line = list(inpu.readline())
    board[i] = line[:3]
inpu.close()
alone = 0
twoTeam = 0
for i in range(3):
    line = []
    for j in range(3):
        line.append(board[i][j])
    if line[0] != line[1] and line[0] != line[2] and line[1] != line[2]:
        pass
    elif line[0] == line[1] and line[1] == line[2]:
        if line[0] not in dict.keys():
            dict[line[0]] = 1
            alone += 1
    else:
        if line[0] == line[2] and (line[0]+line[1]) not in dict.keys():
            dict[line[0]+line[1]] = 1
            dict[line[1]+line[0]] = 1
            twoTeam += 1
        elif line[0] == line[1] and (line[0]+ line[2]) not in dict.keys():
            dict[line[0]+line[2]] = 1
            dict[line[2]+line[0]] = 1
            twoTeam += 1
        elif line[1] == line[2] and (line[0] + line[2]) not in dict.keys():
            dict[line[0]+line[2]] = 1
            dict[line[2]+line[0]] = 1
            twoTeam += 1
for j in range(3):
    line = []
    for i in range(3):
        line.append(board[i][j])
    if line[0] != line[1] and line[0] != line[2] and line[1] != line[2]:
        pass
    elif line[0] == line[1] and line[1] == line[2]:
        if line[0] not in dict.keys():
            dict[line[0]] = 1
            alone += 1
    else:
        if line[0] == line[2] and (line[0]+line[1]) not in dict.keys():
            dict[line[0]+line[1]] = 1
            dict[line[1]+line[0]] = 1
            twoTeam += 1
        elif line[0] == line[1] and (line[0]+ line[2]) not in dict.keys():
            dict[line[0]+line[2]] = 1
            dict[line[2]+line[0]] = 1
            twoTeam += 1
        elif line[1] == line[2] and (line[0] + line[2]) not in dict.keys():
            dict[line[0]+line[2]] = 1
            dict[line[2]+line[0]] = 1
            twoTeam += 1
line = [board[0][0], board[1][1], board[2][2]]
if line[0] != line[1] and line[0] != line[2] and line[1] != line[2]:
    pass
elif line[0] == line[1] and line[1] == line[2]:
    if line[0] not in dict.keys():
        dict[line[0]] = 1
        alone += 1
else:
    if line[0] == line[2] and (line[0]+line[1]) not in dict.keys():
        dict[line[0]+line[1]] = 1
        dict[line[1]+line[0]] = 1
        twoTeam += 1
    elif line[0] == line[1] and (line[0]+ line[2]) not in dict.keys():
        dict[line[0]+line[2]] = 1
        dict[line[2]+line[0]] = 1
        twoTeam += 1
    elif line[1] == line[2] and (line[0] + line[2]) not in dict.keys():
        dict[line[0]+line[2]] = 1
        dict[line[2]+line[0]] = 1
        twoTeam += 1
line = [board[0][2], board[1][1], board[2][0]]
if line[0] != line[1] and line[0] != line[2] and line[1] != line[2]:
    pass
elif line[0] == line[1] and line[1] == line[2]:
    if line[0] not in dict.keys():
        dict[line[0]] = 1
        alone += 1
else:
    if line[0] == line[2] and (line[0]+line[1]) not in dict.keys():
        dict[line[0]+line[1]] = 1
        dict[line[1]+line[0]] = 1
        twoTeam += 1
    elif line[0] == line[1] and (line[0]+ line[2]) not in dict.keys():
        dict[line[0]+line[2]] = 1
        dict[line[2]+line[0]] = 1
        twoTeam += 1
    elif line[1] == line[2] and (line[0] + line[2]) not in dict.keys():
        dict[line[0]+line[2]] = 1
        dict[line[2]+line[0]] = 1
        twoTeam += 1
ou = open("tttt.out", "w")
ou.write(str(alone) + "\n")
ou.write(str(twoTeam))
ou.close()
