def flip(field, i, j):
    global n
    for ii in range(i+1):
        for jj in range(j+1):
            field[ii][jj] = 1-field[ii][jj]
inpu = open("cowtip.in", "r")
n = int(inpu.readline())
field = [0]*n
for i in range(n):
    field[i] = list(inpu.readline())
    for j in range(n):
        field[i][j] = int(field[i][j])
inpu.close()
count = 0
for i in range(n-1, -1, -1):
    for j in range(n-1, -1, -1):
        if field[i][j] == 1:
            flip(field, i, j)
            count += 1
ou = open("cowtip.out", "w")
ou.write(str(count))
ou.close()
