inpu = open("herding.in", "r")
bessie, elsie, mildred = inpu.readline().split(); bessie, elsie, mildred = int(bessie), int(elsie), int(mildred)
cows = [bessie, elsie, mildred]
cows.sort()
bessie, elsie, mildred = cows[0], cows[1], cows[2]
inpu.close()
ou = open("herding.out", "w")
if mildred == elsie+1 and elsie == bessie+1:
    ou.write("0")
elif mildred == elsie+2 or elsie == bessie+2:
    ou.write("1")
else:
    ou.write("2")
ou.write("\n")
maximum = max(mildred-elsie-1, elsie-bessie-1)
ou.write(str(maximum))
ou.close()
