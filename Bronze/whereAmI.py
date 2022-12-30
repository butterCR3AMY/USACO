inpu = open("whereami.in", "r")
n = int(inpu.readline())
houses = list(inpu.readline())
minLen = n
for K in range(1, n+1):
    arr = []
    for start in range(n-K+1):
        done = True
        good = True
        segment = houses[start:start+K]
        if len(arr) > 0:
            for i in range(len(arr)):
                if arr[i] == segment:
                    done = False
                    break
        arr.append(segment)
        if done == False:
            good = False
            break
    if good == True:
        minLen = K
        break
ou = open("whereami.out", "w")
ou.write(str(minLen))
