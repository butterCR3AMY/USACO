inpu = open("div7.in", "r")
n = int(inpu.readline())
breeds = [0]*n
for i in range(n):
    breeds[i] = int(inpu.readline())
inpu.close()
pSums = [0]*(n+1)
for i in range(n):
    pSums[i+1] = pSums[i] + breeds[i]
    pSums[i+1] = (pSums[i+1]) % 7
reverse = [0]*(n+1)
for i in range(n, -1, -1):
    reverse[n-i] = pSums[i]
maxLen = 0
for num in range(7):
    if pSums.count(num) == 0:
        continue
    x = pSums.index(num)
    y = reverse.index(num)
    y = n-y
    len = y-x
    if len > maxLen:
        maxLen = len
ou = open("div7.out", "w")
ou.write(str(maxLen))
ou.close()
