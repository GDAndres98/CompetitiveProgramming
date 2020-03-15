//  UVa10263_Railway
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stdio.h>

#define PI 3.14159265359

using namespace std;


struct pt {
    double x, y;
};
struct line {
    pt p, q;
};

double dist_puntos(pt A, pt B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

pt int_lines(line A, line B) {
    double xa2 = A.q.x - A.p.x, xb2 = B.q.x - B.p.x, xc = A.p.x - B.p.x, ya2 = A.q.y - A.p.y, yb2 = B.q.y - B.p.y, yc =
            A.p.y - B.p.y, d = yb2 * xa2 - xb2 * ya2, zz = xb2 * yc - yb2 * xc;
    return {A.p.x + xa2 * zz / d, A.p.y + ya2 * zz / d};
}


double ds(pt A, pt B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }

pt point_to_line_point(pt x, line s, bool to_line = true) {
    pt aux = {x.x - (s.p.y - s.q.y), x.y + s.p.x - s.q.x};
    pt min = int_lines({x, aux}, s);
    if (to_line)
        return min;
    double dS = ds(s.p, s.q), dP = ds(s.p, x), dQ = ds(s.q, x);
    return (dP + dS < dQ || dQ + dS < dP) ? dP < dQ ? s.p : s.q : min;
};


int main() {
    pt m, p_aux, res;
    line l_aux;
    int rails;
    double min, min_aux;
    while (cin >> m.x >> m.y) {
        cin >> rails;
        rails = 2*rails;
        cin >> l_aux.p.x >> l_aux.p.y >> l_aux.q.x >> l_aux.q.y;
        res = point_to_line_point(m, l_aux, false);
        min = dist_puntos(m, res);

        while (rails-=2) {
            l_aux.p.x = l_aux.q.x;
            l_aux.p.y = l_aux.q.y;
            cin >> l_aux.q.x >> l_aux.q.y;
            p_aux = point_to_line_point(m, l_aux, false);
            min_aux = dist_puntos(m, p_aux);
            if (min > min_aux) {
                min = min_aux;
                res = p_aux;
            }
        }

        cout << fixed << setprecision(4) << res.x << endl << res.y << endl;


    }


}

/*
 *
6
-3
3
0
1
5
5
9
-5
15
3
0
0
1
1
0
2
0

 */