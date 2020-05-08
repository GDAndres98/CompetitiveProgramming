t = int(input())
cases = 1

while (cases <= t):
    mile = 0
    juice = 0
    n = int(input())
    line = input().split()
    for d in line:
        x = int(d)
        mile += 10*(x//30+1)
        juice += 15*(x//60+1)

    # print(mile,juice)
    print("Case %d: "%cases,end="")
    if mile==juice:
        print("Mile Juice %d" % mile)
    elif mile<juice:
        print("Mile %d" % mile)
    else:
        print("Juice %d" % juice)
    cases += 1;