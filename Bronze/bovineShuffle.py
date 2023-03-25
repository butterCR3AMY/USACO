def unshuffle():
    global shuffle, cows, n
    newcows = [0]*n
    for i in range(n):
        newcows[i] = cows[shuffle[i]-1]
    for i in range(n):
        cows[i] = newcows[i]
inpu = open("shuffle.in", "r")
n = int(inpu.readline())
shuffle = inpu.readline().split()
cows = inpu.readline().split()
inpu.close()
for i in range(n):
    shuffle[i] = int(shuffle[i])
for i in range(3):
    unshuffle()
ou = open("shuffle.out", "w")
for i in range(n):
    ou.write(str(int(cows[i])))
    ou.write("\n")
ou.close()
