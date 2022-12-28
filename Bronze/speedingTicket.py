inpu = open("speeding.in","r")
n, m = inpu.readline().split(); n, m = int(n), int(m)
segments = []
for i in range(n):
    length, speed = inpu.readline().split(); length, speed = int(length), int(speed)
    for j in range(length):
        segments.append(speed)
journey = []
for i in range(m):
    length, speed = inpu.readline().split(); length, speed = int(length), int(speed)
    for j in range(length):
        journey.append(speed)
maxDiff = 0
for i in range(100):
    diff = journey[i]-segments[i]
    if diff > maxDiff:
        maxDiff = diff
ou = open("speeding.out", "w")
ou.write(str(maxDiff))
