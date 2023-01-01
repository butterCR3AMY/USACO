inpu = open("gymnastics.in", "r")
k, n = inpu.readline().split(); k, n = int(k), int(n)
ranks = [0]*k
for i in range(k):
    ranks[i] = inpu.readline().split()
    for j in range(n):
        ranks[i][j] = int(ranks[i][j])
inpu.close()
pairs = 0
for n1 in range(1, n+1):
    for n2 in range(1, n+1):
        if n1 == n2:
            continue
        done = True
        for i in range(k):
            x = ranks[i].index(n1)
            y = ranks[i].index(n2)
            if x > y:
                done = False
        if done == True:
            pairs += 1
ou = open("gymnastics.out", "w")
ou.write(str(pairs))
ou.close()
