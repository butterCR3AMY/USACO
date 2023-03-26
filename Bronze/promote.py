inpu = open("promote.in", "r")
levels = [0]*4
for i in range(4):
    levels[i] = inpu.readline().split()
inpu.close()
differences = [0]*4
for i in range(4):
    differences[i] = int(levels[i][1])-int(levels[i][0])
ans = [0]*3
for i in range(1, 4):
    for j in range(0, i):
        ans[j] += differences[i]
ou = open("promote.out", "w")
for i in range(3):
    ou.write(str(ans[i]))
    ou.write("\n")
ou.close()
