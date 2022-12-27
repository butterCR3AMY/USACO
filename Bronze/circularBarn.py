inpu = open("cbarn.in", "r")
n = int(inpu.readline())
peoples = ""
for i in range(n):
    x = inpu.readline()
    peoples += x + " "
peoples = peoples.split()
inpu.close()
for i in range(len(peoples)):
    peoples[i] = int(peoples[i])
smallest = 100000000
for i in range(len(peoples)-1, -1, -1):
    curnum = 0
    for j in range(len(peoples)):
        if j - i >= 0:
            curnum += peoples[j]*(j-i)
        else:
            curnum += peoples[j]*((len(peoples)-1-i)+1+j)
    if curnum <= smallest:
        smallest = curnum
ou = open("cbarn.out", "w")
ou.write(str(smallest))
ou.close()
