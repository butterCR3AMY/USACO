def probXwinY(A, B):
    outcomes = 0
    for i in range(4):
        for j in range(4):
            if A[i] > B[j]:
                outcomes += 1
    return outcomes
n = int(input())
for i in range(n):
    possible = False
    both = [0]*8
    both = input().split()
    for i in range(8):
        both[i] = int(both[i])
    A = both[:4]
    B = both[4:]
    AwinBchance = probXwinY(A,B)
    BwinAchance = probXwinY(B,A)
    AwinB, BwinA = False, False
    if AwinBchance > BwinAchance:
        AwinB = True
    elif BwinAchance > AwinBchance:
        BwinA = True
    for j in range(1, 11):
        for k in range(1, 11):
            for l in range(1, 11):
                for m in range(1, 11):
                    C = [j,k,l,m]
                    BwinCchance = probXwinY(B,C)
                    CwinBchance = probXwinY(C,B)
                    BwinC, CwinB = False, False
                    if BwinCchance > CwinBchance:
                        BwinC = True
                    elif CwinBchance > BwinCchance:
                        CwinB = True
                    CwinAchance = probXwinY(C,A)
                    AwinCchance = probXwinY(A,C)
                    CwinA, AwinC = False, False
                    if CwinAchance > AwinCchance: 
                        CwinA = True
                    elif AwinCchance > CwinAchance:
                        AwinC = True
                    # A > B > C > A
                    # B > A > C > B
                    if (AwinB and BwinC and CwinA) or (BwinA and CwinB and AwinC):
                        possible = True
                        print("yes")
                        break
                if possible:
                    break
            if possible:
                break
        if possible:
            break
    if not possible:
        print("no")
