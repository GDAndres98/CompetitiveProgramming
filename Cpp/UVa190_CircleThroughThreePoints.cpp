//UVa 190 - Circle Through Three Points
//UVa190_CircleThroughThreePoints
#define PI 3.14159265359

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stdio.h>

#define MAX 60000
#define EPS 10e-7

using namespace std;


struct pt {
    double x, y;
};

struct line {
    pt p, q;
};

pt p_A, p_B, p_C;

pt intLineas(line A, line B) {
    double xa2 = A.q.x - A.p.x, xb2 = B.q.x - B.p.x, xc = A.p.x - B.p.x, ya2 = A.q.y - A.p.y, yb2 = B.q.y - B.p.y, yc =
            A.p.y - B.p.y, d = yb2 * xa2 - xb2 * ya2, zz = xb2 * yc - yb2 * xc;
    return {A.p.x + xa2 * zz / d, A.p.y + ya2 * zz / d};
}

double distPuntos(pt A, pt B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

line bisectriz(pt A, pt B) {
    pt p1 = {(A.x + B.x) / 2, (A.y + B.y) / 2};
    pt p2 = {p1.x - (B.y - A.y), p1.y + B.x - A.x};
    return {p1, p2};
}

char signoInv(double x) {
    if (x > 0) {
        return '-';
    } else {
        return '+';
    }
}

char signo(double x) {
    if (x <= 0) {
        return '+';
    } else {
        return '-';
    }
}


int main() {



    while (cin >> p_A.x >> p_A.y >> p_B.x >> p_B.y >> p_C.x >> p_C.y) {
        line J = bisectriz(p_A, p_B);
        line K = bisectriz(p_B, p_C);
        pt centro = intLineas(J, K);
        double radio = distPuntos(centro, p_B);

        printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n", signoInv(centro.x), abs(centro.x), signoInv(centro.y), abs(centro.y), radio);

        double aux_num = radio*radio-centro.x*centro.x-centro.y*centro.y;


        printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n\n", signo(centro.x), abs(centro.x*2), signoInv(centro.y), abs(centro.y*2), signo(aux_num), abs(aux_num));


    }

    return 0;
}

/*
7.0 -5.0 -1.0 1.0 0.0 -6.0
1.0 7.0 8.0 6.0 7.0 -2.0
*/