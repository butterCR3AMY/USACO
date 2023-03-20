def check():
    global cows, order
    cur = 0
    mark = [-1]*n
    for i in range(n):
        if cows[i] == 0:
            continue
        mark[cows[i]-1] = i
    for i in range(m):
        if mark[order[i]-1] != -1:
            if cur > mark[order[i]-1]:
                return False
            cur = mark[order[i]-1]
            continue
        for j in range(cur, n):
            if cows[j] == 0:
                cows[j] = order[i]
                cur = j
                mark[order[i]-1] = j
                break
    return True
inpu = open("milkorder.in", "r")
n, m, k = inpu.readline().split(); n, m, k = int(n), int(m), int(k)
OJ = [0]*n
cows = [0]*n
order = [0]*m
order = inpu.readline().split()
for i in range(m):
    order[i] = int(order[i])
for i in range(k):
    cow, pos = inpu.readline().split()
    cow, pos = int(cow), int(pos)
    OJ[pos-1] = cow
    cows[pos-1] = cow
inpu.close()
ans = 0
for i in range(n):
    for j in range(n):
        cows[j] = OJ[j]
    if cows[i] != 0:
        continue
    cows[i] = 1
    if check() == True:
        ans = i+1
        break
    cows[i] = 0
ou = open("milkorder.out", "w")
ou.write(str(ans))
ou.close
