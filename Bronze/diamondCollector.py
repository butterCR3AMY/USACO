inpu = open("diamond.in", "r")
n, k = inpu.readline().split(); n, k = int(n), int(k)
diamonds = [0]*n
for i in range(n):
    diamonds[i] = int(inpu.readline())
inpu.close()
diamonds.sort()
max = 0
for i in range(n):
    for j in range(i+1, n):
        if diamonds[j]-diamonds[i] <= k:
            if j-i+1 > max:
                max = j-i+1
ou = open("diamond.out", "w")
ou.write(str(max))
ou.close()
