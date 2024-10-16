nums = [0]*7
nums = input().split()
for i in range(len(nums)):
    nums[i] = int(nums[i])
for A in range(len(nums)):
    for B in range(len(nums)):
        for C in range(len(nums)):
            if A == B or B == C and A == C:
                continue
            try:
                x = nums.index(nums[A]+nums[B])
            except:
                continue
            try:
                x = nums.index(nums[A]+nums[C])
            except:
                continue
            try:
                x = nums.index(nums[B]+nums[C])
            except:
                continue
            try:
                x = nums.index(nums[A]+nums[C]+ nums[B])
            except:
                continue
            arr = [nums[A], nums[B], nums[C]]
            arr.sort()
            for i in range(2):
                print(arr[i], end = " ")
            print(arr[2], end = "\n")
            exit()
