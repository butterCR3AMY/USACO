inpu = open("cowsignal.in", "r")
m, n, k = inpu.readline().split(); m, n, k = int(m), int(n), int(k)
signal = [0]*m
for i in range(m):
    signal[i] = list(inpu.readline())
inpu.close()
ou = open("cowsignal.out", "w")
for i in range(m):
    for blank in range(k):
        for j in range(n):
            ou.write((signal[i][j]*k))
        ou.write("\n")
ou.close()
