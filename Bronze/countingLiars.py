#getting the mat
def comp(a):
    return [ord(a[0]), a[1]]
n = int(input())
mat = [0]*n
for i in range(n):
    mat[i] = input().split()
    mat[i][1] = int(mat[i][1])
mat.sort(key = comp)
#looking for the last L and first G
G = 0
L = n-1
for i in range(n):
    if mat[i][0] == "L":
        L = i
        G = i-1
        break

#How many L's work for the G's
minLiars = n
for i in range(0, G+1):
    firstWorkingL = n
    for j in range(L, n):
        if mat[i][1] <= mat[j][1]:
            firstWorkingL = j
            break
    curLiars = (G-i)+ (firstWorkingL-L)
    if curLiars < minLiars:
        minLiars = curLiars
for i in range(L, n):
    lastWorkingG = -1
    for j in range(G, -1, -1):
        if mat[i][1] >= mat[j][1]:
            lastWorkingG = j
            break
    curLiars = (i-L)+ (G-lastWorkingG)
    if curLiars < minLiars:
        minLiars = curLiars
print(minLiars)
