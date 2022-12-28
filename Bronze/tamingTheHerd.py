inpu = open("taming.in", "r")
ou = open("taming.out", "w")
n = int(inpu.readline())
OGlog = [0]*n
log = inpu.readline().split()
for i in range(n):
    log[i] = int(log[i])
    OGlog[i] = int(log[i])
max = 0
for i in range(n-1, -1, -1):
    if log[i] == -1:
        if i < n-1:
            if log[i+1] > 0:
                log[i] = log[i+1]-1
            else:
                log[i] = 0
        else:
            log[i] = 0
    else:
        if i < n-1 and log[i+1] > 0:
            if log[i+1] - log[i] != 1:
                ou.write("-1")
                exit()
    if i == 0:
        if log[i] > 0:
            ou.write("-1")
            exit()
        else:
            log[i] = 0
    if log[i] == 0:
        max += 1
min = 0
for i in range(n-1, -1, -1):
    if OGlog[i] == -1:
        if i < n-1:
            if OGlog[i+1] > 0:
                OGlog[i] = OGlog[i+1]-1
    if i == 0:
        if OGlog[i] > 0:
            ou.write("-1")
            exit()
        else:
            OGlog[i] = 0
    if OGlog[i] == 0:
        min += 1
ou.write(str(min) + " " + str(max))
ou.close()
