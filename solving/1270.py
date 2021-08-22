n = int(input())
for i in range(n):
    lst = input().split()
    ti = lst[0]
    lst = lst[1:]
    m = {}
    syj = True
    for j in lst:
        try:
            m[j] += 1
            if m[j] > ti/2:
                print(j)
                syj = False
                break
        except:
            m[j] = 1
    if(syj):
        print("SYJKGW")