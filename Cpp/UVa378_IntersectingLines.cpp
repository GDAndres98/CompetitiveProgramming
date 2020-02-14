// UVA 378
// UVa378_IntersectingLines

#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.14159265359


using namespace std;

struct pt {
    double x, y;
};

bool operator<(const pt &a1, const pt &a2) {
    if (a1.x != a2.x) return a1.x < a2.x;
    return a1.y < a2.y;
}

bool operator!=(const pt &a1, const pt &a2) {
    if (a1.x != a2.x) return true;
    return a1.y != a2.y;
}

struct line {
    pt p, q;
};

bool operator<(const line &a1, const line &a2) {
    if (a1.p != a2.p) return a1.p < a2.p;
    return a1.q < a2.q;
}

line inputLine() {
    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    if (a != b && b < a) {
        return {b, a};
    }
    return {a, b};

}

bool sameLine(line A, line B) {
    return false;
}

pt intLineas(line A, line B) {
    double xa2 = A.q.x - A.p.x, xb2 = B.q.x - B.p.x, xc = A.p.x - B.p.x, ya2 = A.q.y - A.p.y, yb2 = B.q.y - B.p.y, yc =
            A.p.y - B.p.y, d = yb2 * xa2 - xb2 * ya2, zz = xb2 * yc - yb2 * xc;
    return {A.p.x + xa2 * zz / d, A.p.y + ya2 * zz / d};
}


int main() {
    double n;
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    for (int cases = 0; cases < n; cases++) {
        line A = inputLine();
        line B = inputLine();
        if (A < B) {
            line t = A;
            A = B;
            B = t;
        }

        pt res = intLineas(A, B);
        if (isinf(res.x) || isinf(res.y))
            cout << "NONE" << endl;

         else if (isnan(res.x) || isnan(res.y))
            cout << "LINE" << endl;

         else

            cout << fixed << setprecision(2) << "POINT "<<res.x << " " << res.y << endl;
    }
    cout << "END OF OUTPUT" << endl;

}


/*
 *
1 2 3 4
1 2 3 4
1 2 3 4

 */