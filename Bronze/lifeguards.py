inpu = open("lifeguards.in", "r")
n = int(inpu.readline())
OJ = [0]*1000
time = [0]*1000
mark = [0]*n
starts = [0]*n
ends = [0]*n
for i in range(n):
    starts[i], ends[i] = inpu.readline().split(); starts[i], ends[i] = int(starts[i])-1, int(ends[i])-1
inpu.close()
max = 0
for fired in range(n):
    covered = 0
    for i in range(1000):
        time[i] = 0
    for j in range(n):
        if j == fired:
            continue
        for i in range(starts[j]-1, ends[j]-1):
            if time[i] == 0:
                time[i] = 1
                covered += 1
    if covered > max:
        max = covered
ou = open("lifeguards.out", "w")
ou.write(str(max))
