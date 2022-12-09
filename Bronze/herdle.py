rightAns = [0]*3
for i in range(3):
    rightAns[i] = list(input())
guess = [0]*3
for i in range(3):
    guess[i] = list(input())
greenCount = 0
yellowCount = 0
#go through right answer
for i in range(3):
    for j in range(3):
        if guess[i][j] == rightAns[i][j] and guess[i][j] != 0 and rightAns[i][j] != 0:
            greenCount += 1
            guess[i][j] = 0
            rightAns[i][j] = 0
#go through guess
for i in range(3):
    for j in range(3):
        for k in range(3):
            for l in range(3):
                if k == i and l == j:
                    continue
                if guess[k][l] == rightAns[i][j] and guess[k][l] != 0 and rightAns[i][j] != 0:
                    yellowCount += 1
                    guess[k][l] = 0
                    rightAns[i][j] = 0
                    break
print(greenCount)
print(yellowCount)
