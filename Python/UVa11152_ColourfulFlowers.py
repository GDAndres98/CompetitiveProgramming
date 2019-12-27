from math import sqrt, pi

while (True):
    try:
        a, b, c = [float(i) for i in input().split()]

        s = (a + b + c) / 2.0
        triangle = sqrt(s * (s - a) * (s - b) * (s - c))

        r = triangle/s
        circInt = r*r*pi

        r = a*b*c / (4*triangle)
        circExt = r*r*pi

        circExt -= triangle
        triangle -= circInt

        print("%.4f %.4f %.4f" % (circExt, triangle, circInt))
    except Exception as e:
        break
