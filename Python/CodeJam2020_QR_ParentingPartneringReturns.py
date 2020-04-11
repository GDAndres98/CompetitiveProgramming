t = int(input())
x = 1
while x <= t:
    n = int(input())
    posible = True
    res=[]
    times=[]
    for i in range(n):
        res.append('i')
        line  = input().split()
        times.append([int(line[0]),int(line[1]),i])
    times.sort()
    
    a=-1
    b=-1
    i=0
    while i<n:
        if a<0 or times[a][1]<=times[i][0]:
            a=i
            res[times[i][2]]='J'
        elif b<0 or times[b][1]<=times[i][0]:
            b=i
            res[times[i][2]]='C'
        else:
            posible=False
        i+=1
    if posible:
        print("Case #%d: " % x,*res,sep="")
    else:
        print("Case #%d: IMPOSSIBLE" % x)
    x+=1