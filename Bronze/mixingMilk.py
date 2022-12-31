def pour1to2():
    global first
    global second
    x = min(second[0]-second[1], first[1])
    first[1] -= x
    second[1] += x
def pour2to3():
    global second
    global third
    x = min(third[0]-third[1], second[1])
    second[1] -= x
    third[1] += x
def pour3to1():
    global third
    global first
    x = min(first[0]-first[1], third[1])
    third[1] -= x
    first[1] += x
inpu = open("mixmilk.in", "r")
first = inpu.readline().split(); first[0], first[1] = int(first[0]), int(first[1])
second = inpu.readline().split(); second[0], second[1] = int(second[0]), int(second[1])
third = inpu.readline().split(); third[0], third[1] = int(third[0]), int(third[1])
for i in range(33):
    pour1to2()
    pour2to3()
    pour3to1()
pour1to2()
ou = open("mixmilk.out", "w")
ou.write(str(first[1])+"\n")
ou.write(str(second[1])+"\n")
ou.write(str(third[1])+"\n")
