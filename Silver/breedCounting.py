inpu = open("bcount.in", "r")
ou = open("bcount.out", "w")
n, q = inpu.readline().split(); n, q = int(n), int(q)
breeds = [0]*n
for i in range(n):
    breeds[i] = int(inpu.readline())
pSums = [0]*(n+1)
pSums[0] = [0,0,0]
g = 0
h = 0
j = 0
for end in range(n):
    if breeds[end] == 1:
        g += 1
    elif breeds[end] == 2:
        h += 1
    else:
        j += 1
    pSums[end+1] = [g, h, j]
for i in range(q):
    start, end = inpu.readline().split(); start, end = int(start), int(end)
    start -= 1
    end -= 1
    G = pSums[end+1][0] - pSums[start][0]
    H = pSums[end+1][1] - pSums[start][1]
    J = pSums[end+1][2] - pSums[start][2]
    ou.write(str(G) + " "+ str(H) + " " + str(J))
    ou.write("\n")
inpu.close()
ou.close()
