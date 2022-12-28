cowphabet = input()
heard = input()
pos = 0
count = 0
while True:
    for i in range(26):
        if cowphabet[i] == heard[pos]:
            pos += 1
            if pos == len(heard):
                break
    count += 1
    if pos == len(heard):
        break
print(count)
