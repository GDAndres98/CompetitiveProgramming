t = int(input())
x = 1
while x <= t:
    r = []
    aux = set()
    mx = 0
    line = input()
    s = []
    for c in line:
        r.append(".")
        mx = max(mx, int(c))
        s.append(int(c))
    while mx > 0:
        i = 0
        found = False
        while (i < len(s)):
            if s[i] >= mx and not found:
                r[i] = '(' + r[i]
                found = True
            if found and s[i] < mx:
                r[i - 1] = r[i - 1] + ')'
                found = False
            i += 1
        if found:
            r[i - 1] = r[i - 1] + ')'
        mx -= 1
    res = ""
    for idx, e in enumerate(r):
        for c in e:
            if c == '.':
                res += str(s[idx])
            else:
                res += c
    print("Case #%d: %s" %(x,res))

    x += 1
