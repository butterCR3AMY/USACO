inpu = open("angry.in", "r")
n = int(inpu.readline())
bales = [0]*n
for i in range(n):
    bales[i] = int(inpu.readline())
bales.sort()
print(bales)
maxi = 0
trigger = 0
for i in range(n):
    time = 1
    count = 1
    if i < (n-1):
        bomber = i
        for forward in range(i+1, n):
            if bales[forward]- bales[bomber] <= time:
                count += 1
                if forward < (n-1):
                    if bales[forward+1]- bales[bomber] > time:
                        bomber = forward
                        time += 1
                else:
                    bomber = forward
                    time += 1
            else:
                break
    time = 1
    if i > 0:
        bomber = i
        for backward in range(i-1, -1, -1):
            if bales[bomber]-bales[backward] <= time:
                count += 1
                if backward > 0:
                    if bales[bomber]- bales[backward-1] > time:
                        bomber = backward
                        time += 1
                else:
                    bomber = backward
                    time += 1
            else:
                break
    if count >= maxi:
        maxi = count
        trigger = bales[i]


ou = open("angry.out", "w") 
ou.write(str(maxi))
ou.close()
