inpu = open("pails.in", "r")
x, y, m = inpu.readline().split(); x, y, m = int(x), int(y), int(m)
inpu.close()
max = 0
for i in range(m):
    for j in range(m):
        if i*x + j*y <= m and i*x+j*y > max:
            max = i*x + j*y
ou = open("pails.out", "w")
ou.write(str(max))
