inpu = open("word.in", "r")
n, k = inpu.readline().split(); n, k = int(n), int(k)
essay = [""]*n
essay = inpu.readline().split()
inpu.close()
ou = open("word.out", "w")
count = 0
for i in range(len(essay)):
    count += len(essay[i])
    if count > k:
        count = len(essay[i])
        ou.write("\n")
        ou.write(essay[i])
        continue
    else:
        if i > 0:
            ou.write(" "+essay[i])
        else:
            ou.write(essay[i])
ou.close()
