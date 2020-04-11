t = int(input())
x = 1
while x <= t:
    n = int(input())
    arr = []
    maxleft = 0
    il = -1
    maxright = 0
    ir = -1
    for i in range(n):
        line = input().split("*")
        arr.append([line[0], line[1]])
        if len(arr[i][0]) > maxleft:
            il = i
            maxleft = len(arr[i][0])
        if len(arr[i][1]) > maxright:
            ir = i
            maxright = len(arr[i][1])

    posible = True
    reverb = arr[ir][1][::-1]
    for i in range(n):
        for j,c in enumerate(arr[i][0]):
            if arr[il][0][j]!=c:
                posible=False
        for j,c in enumerate(reversed(arr[i][1])):
            if reverb[j]!=c:
                posible=False
        if not posible:
            break

    if posible:
        print("Case #%d: %s%s" % (x, arr[il][0],arr[ir][1]))
    else:
        print("Case #%d: *" % (x))

    x+=1
