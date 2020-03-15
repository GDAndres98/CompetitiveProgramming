//  UVa10180_RopeCrisisInRopeland
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stdio.h>

#define PI 3.14159265359
#define DUM 10111.0

using namespace std;


struct pt {
    double x, y;

};

struct line {
    pt p, q;
    double a, b, c;

    line(pt p, pt q) : p(p), q(q) {
        if (p.x == q.x) {
            a = 1;
            b = 0;
            c = -p.x;
        } else {
            a = -(p.y - q.y) / (p.x - q.x);
            b = 1;
            c = -(a * p.x) - (b * p.y);
        }
    }
};


// O(1)
double dist_puntos(pt A, pt B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

// O(1)
// Paralelas: Si contiene un inf en una de las coordenadas
// Es la misma: Si lo anterior no se cumple y contiene un nan en una de las coordenadas
pt int_lines(line A, line B) {
    double xa2 = A.q.x - A.p.x, xb2 = B.q.x - B.p.x, xc = A.p.x - B.p.x, ya2 = A.q.y - A.p.y,
            yb2 = B.q.y - B.p.y, yc = A.p.y - B.p.y, d = yb2 * xa2 - xb2 * ya2, zz = xb2 * yc - yb2 * xc;
    return {A.p.x + xa2 * zz / d, A.p.y + ya2 * zz / d};
}

// O(1)
double ds(pt A, pt B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }

// O(1)
// centro del circulo en (0,0)
vector<pt> int_line_circle(line l, double r) {
    vector<pt> res;
    double x0 = -l.a * l.c / (l.a * l.a + l.b * l.b), y0 = -l.b * l.c / (l.a * l.a + l.b * l.b);
    if (l.c * l.c > r * r * (l.a * l.a + l.b * l.b))
        return res;
    else if (abs(l.c * l.c - r * r * (l.a * l.a + l.b * l.b)) < 10e-6) {
        res.push_back({x0, y0});
    } else {
        double d = r * r - l.c * l.c / (l.a * l.a + l.b * l.b);
        double mult = sqrt(d / (l.a * l.a + l.b * l.b));
        double ax, ay, bx, by;
        ax = x0 + l.b * mult;
        bx = x0 - l.b * mult;
        ay = y0 - l.a * mult;
        by = y0 + l.a * mult;
        res.push_back({ax, ay});
        res.push_back({bx, by});
    }
    return res;
}

// O(1)
vector<pt> circle_tangents_by_point(pt c, double r, pt p) {
    vector<pt> res;
    double b = sqrt((p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y));
    double th = acos(r / b);
    double d = atan2(p.y - c.y, p.x - c.x);
    double d1 = d + th;
    double d2 = d - th;
    res.push_back({c.x + r * cos(d1), c.y + r * sin(d1)});
    res.push_back({c.x + r * cos(d2), c.y + r * sin(d2)});
    return res;
}

// O(1)
// Angulo en el vertice b
double angle(pt a, pt b, pt c) {
    double ab = dist_puntos(a, b);
    double bc = dist_puntos(b, c);
    double ca = dist_puntos(c, a);
    return acos((ab * ab + bc * bc - ca * ca) / (2 * ab * bc));
};

// O(1)
double arc_circle(pt a, pt b, pt c, double r) {
    return angle(a, c, b) * r;
}

//MODIFICADO
pt point_to_line_point(pt x, line s, bool to_line = true) {
    pt aux = {x.x - (s.p.y - s.q.y), x.y + s.p.x - s.q.x};
    pt min = int_lines({x, aux}, s);
    if (to_line) return min;
    double dS = ds(s.p, s.q), dP = ds(s.p, x), dQ = ds(s.q, x);
    return (dP + dS < dQ || dQ + dS < dP) ? pt{DUM, DUM} : min;
};

int main() {

    int t;
    double r, res;
    pt a, b;
    cin >> t;
    while (t--) {
        cin >> a.x >> a.y >> b.x >> b.y >> r;
        if (a.x == b.x && a.y == b.y) {
            res = 0;
        } else {
            line AB = line(a, b);
            pt p = point_to_line_point({0, 0}, AB, false);
            if (p.x == DUM || dist_puntos(p, {0, 0}) >= r) {
                res = dist_puntos(a, b);
            } else {
                vector<pt> tan1 = circle_tangents_by_point({0, 0}, r, a);
                vector<pt> tan2 = circle_tangents_by_point({0, 0}, r, b);
                res = dist_puntos(a, tan1[0]) + dist_puntos(b, tan2[1]) + arc_circle(tan1[0], tan2[1], {0, 0}, r);
                res = min(res,
                          dist_puntos(a, tan1[1]) + dist_puntos(b, tan2[0]) + arc_circle(tan1[1], tan2[0], {0, 0}, r));
            }
        }
        cout << fixed << setprecision(3) << res << endl;
    }


}

/*
 *
2
1 1 -1 -1 1
1 1 -1 1 1

 */