t = int(input())
x = 1
while x<=t:
    n = int(input())
    filas = []
    columnas = []
    for i in range(0,n):
      filas.append(set())
      columnas.append(set())
    total=0
    for i in range(0,n):
      line=input().split()
      for j in range(0,n):
        m = int(line[j])
        if i==j:
          total+=m
        filas[i].add(m)
        columnas[j].add(m)
    f=0
    c=0
    for fila in filas:
      if len(fila)<n:
        f+=1
    for col in columnas:
      if len(col)<n:
        c+=1

    print("Case #%d: %d %d %d" %(x,total,f,c))
    x+=1
