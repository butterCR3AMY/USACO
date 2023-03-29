inpu = open("triangles.in", "r")
n = int(inpu.readline())
fenceposts = [0]*n
for i in range(n):
    fenceposts[i] = inpu.readline().split()
    fenceposts[i][0], fenceposts[i][1] = int(fenceposts[i][0]), int(fenceposts[i][1])
inpu.close()
maxArea = 0
for i in range(n):
    for j in range(n):
        for k in range(n):
            if i == j or j == k or i == k:
                continue
            curArea = 0
            if fenceposts[i][0] == fenceposts[j][0]:
                if fenceposts[i][1] == fenceposts[k][1]:
                    curArea = abs(fenceposts[i][1]-fenceposts[j][1])*abs(fenceposts[i][0]-fenceposts[k][0])
                if fenceposts[j][1] == fenceposts[k][1]:
                    curArea = abs(fenceposts[i][1]-fenceposts[j][1])*abs(fenceposts[k][0]-fenceposts[j][0])
            if fenceposts[j][0] == fenceposts[k][0]:
                if fenceposts[i][1] == fenceposts[j][1]:
                    curArea = abs(fenceposts[i][1]-fenceposts[j][1])*abs(fenceposts[i][0]-fenceposts[j][0])
                if fenceposts[i][1] == fenceposts[k][1]:
                    curArea = abs(fenceposts[i][1]-fenceposts[j][1])*abs(fenceposts[i][0]-fenceposts[k][0])
            if fenceposts[i][0] == fenceposts[k][0]:
                if fenceposts[i][1] == fenceposts[j][1]:
                    curArea = abs(fenceposts[i][1]-fenceposts[j][1])*abs(fenceposts[i][0]-fenceposts[j][0])
                if fenceposts[k][1] == fenceposts[j][1]:
                    curArea = abs(fenceposts[i][1]-fenceposts[j][1])*abs(fenceposts[k][0]-fenceposts[j][0])
            if curArea > maxArea:
                maxArea = curArea
ou = open("triangles.out", "w")
ou.write(str(maxArea))
ou.close()
