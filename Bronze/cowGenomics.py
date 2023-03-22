inpu = open("cownomics.in", "r")
n, m = inpu.readline().split(); n, m = int(n), int(m)
spotties = [0]*n
for i in range(n):
    line = [""]*m
    line = inpu.readline()
    if line[len(line)-1] == "\n":
        line = line[:len(line)-1]
    spotties[i] = list(line)
plains = [0]*n
for i in range(n):
    line = [""]*m
    line = inpu.readline()
    if line[len(line)-1] == "\n":
        line = line[:len(line)-1]
    plains[i] = list(line)
inpu.close()
ACGT = [0]*4
count = 0
for pos in range(m):
    for i in range(4):
        ACGT[i] = 0
    works = True
    for i in range(n):
        if plains[i][pos] == "A":
            ACGT[0] = 1
        elif plains[i][pos] == "C":
            ACGT[1] = 1
        elif plains[i][pos] == "G":
            ACGT[2] = 1
        elif plains[i][pos] == "T":
            ACGT[3] = 1
    for i in range(n):
        if spotties[i][pos] == "A" and ACGT[0] == 1:
            works = False
            break
        elif spotties[i][pos] == "C" and ACGT[1] == 1:
            works = False
            break
        elif spotties[i][pos] == "G" and ACGT[2] == 1:
            works = False
            break
        elif spotties[i][pos] == "T" and ACGT[3] == 1:
            works = False
            break
    if works == True:
        count += 1
ou = open("cownomics.out", "w")
ou.write(str(count))
ou.close()
