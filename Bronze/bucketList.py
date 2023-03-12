inpu = open("blist.in", "r")
n = int(inpu.readline())
time = [0]*1000
for q in range(n):
    start, end, bucket = inpu.readline().split()
    start, end, bucket = int(start), int(end), int(bucket)
    for i in range(start-1, end):
        time[i] += bucket
inpu.close()
ans = max(time)
ou = open("blist.out", "w")
ou.write(str(ans))
print(ans)
ou.close()
