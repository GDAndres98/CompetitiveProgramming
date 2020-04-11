posible = False
n = 0
k = 0


def checkSum(mat):
    global posible
    sum = 0
    for i in range(n):
        sum += mat[i][i]
    if sum == k:
        posible = True


def canPut(mat, i, j, x):
    for ci in range(i):
        if mat[ci][j] == x:
            return False
    for cj in range(j):
        if mat[i][cj] == x:
            return False
    return True


def solve(mat, i, j):
    global posible, n
    if (j == n):
        j = 0
        i += 1
    if (i == n):
        checkSum(mat)
        return
    for x in range(1, n + 1):
        if not posible and canPut(mat, i, j, x):
            mat[i][j] = x
            solve(mat, i, j + 1)


def main():
    global posible, n, k
    t = int(input())
    x = 1
    while x <= t:
        posible = False
        line = input().split()
        n = int(line[0])
        k = int(line[1])
        mat = []

        for i in range(n):
            mat.append([])
            for j in range(n):
                mat[i].append(0)

        solve(mat, 0, 0)

        if posible:
            print("Case #%d: POSSIBLE" % x)
            for i in range(n):
                print(*mat[i], sep=" ")
        else:
            print("Case #%d: IMPOSSIBLE" % x)
        x += 1

main()
