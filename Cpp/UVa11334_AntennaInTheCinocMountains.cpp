// Referencias: http://www.illusioncatalyst.com/notes_files/mathematics/line_cone_intersection.php
// WRONG ANSWER
// UVa11334_AntennaInTheCinocMountains


#include <algorithm>
#include <iostream>
#include <cmath>


using namespace std;

const double EPS = 10e-7;

int cmp(double x, double y) {
    return abs(x - y) < EPS ? 0 : x < y + EPS ? -1 : 1;
}

struct pt {
    double x, y, z;

    pt(double x, double y, double z) : x(x), y(y), z(z) {}

    pt() {};

    double operator^(const pt &o) const {
        return x * o.x + y * o.y + z * o.z;
    }

    pt operator*(const pt &o) const {
        return {y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x};;
    }

    pt operator+(const pt &o) const {
        return {x + o.x, y + o.y, z + o.z};
    }

    pt operator-(const pt &o) const {
        return {x - o.x, y - o.y, z - o.z};
    }

    pt operator/(const double o) const {
        return {x / o, y / o, z / o};
    }

    pt operator*(const double o) const {
        return {x * o, y * o, z * o};
    }

    bool operator<(const pt &o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }

    bool operator!=(const pt &o) const {
        if (x != o.x) return true;
        if (z != o.z) return true;
        return y != o.y;
    }

    double dist(pt &B) const {
        return sqrt(ds(B));
    }

    double ds(pt &B) const {
        return (x - B.x) * (x - B.x) + (y - B.y) * (y - B.y) + (z - B.z) * (z - B.z);
    }

    void print() const {
        cout << x << ", " << y << ", " << z << endl;
    }

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

struct Cone {
    pt C; // Centro base del cono
    pt H; // Punta del cono
    double r; // radio del cono;

};


double ds(pt A) { return A.x * A.x + A.y * A.y + A.z * A.z; }

double shortDistance(pt &line_point1, pt &line_point2,
                     pt point) {
    pt AB = line_point2 - line_point1;
    pt AC = point - line_point1;
    double area = ds(AB * AC);
    double CD = area / ds(AB);
    return CD;
}

double pointInSegment(pt &line_point1, pt &line_point2,
                      pt point) {
    double d1 = line_point1.dist(point);
    double d2 = line_point2.dist(point);
    double dr = line_point1.dist(line_point2);
    return cmp(d1 + d2, dr) == 0;
}

bool pointInsideCone(Cone &c, pt &a) {
    long double dx = a.x - c.H.x;
    long double dy = a.y - c.H.y;
    long double d = sqrt(dx * dx + dy * dy);
    if (cmp(d, c.r) > 0) return false;
    long double p = (c.r - d) / c.r * c.H.z;
    return cmp(a.z, p) <= 0;

}

bool coneSegmentIntersection(Cone cone, pt A, pt B) {
    double h = cone.C.dist(cone.H);
    pt nh = (cone.C - cone.H) / h;
    double m = (cone.r * cone.r) / (h * h);
    pt v = B - A;
    pt w = A - cone.H;

    double at = (v ^ v) - m * (v ^ nh) * (v ^ nh) - (v ^ nh) * (v ^ nh);
    double bt = 2 * ((v ^ w) - m * (v ^ nh) * (w ^ nh) - (v ^ nh) * (w ^ nh));
    double ct = (w ^ w) - m * (w ^ nh) * (w ^ nh) - (w ^ nh) * (w ^ nh);

    double troot = bt * bt - 4 * at * ct;


//   cout << "root -> " << cmp(troot,0) << endl;

    if (cmp(troot, 0) < 0) {
//        cout<<"Caso 0"<<endl;
        return false;
    }

    if (cmp(troot, 0) > 0) {
        double sol1 = (-bt + sqrt(troot)) / (2 * at);
        double sol2 = (-bt - sqrt(troot)) / (2 * at);
        pt inter1 = A + (v * sol1);
        pt inter2 = A + (v * sol2);

//        inter1.print();
        if (pointInsideCone(cone, inter1) && pointInSegment(A, B, inter1)) {
//            cout << "caso 1.1" << endl;
            return true;
        }
//        inter2.print();
        if (pointInsideCone(cone, inter2) && pointInSegment(A, B, inter2)) {
//            cout << "caso 1.2" << endl;
            return true;
        }

        if (pointInsideCone(cone, A) || pointInsideCone(cone, B))
            return true;
    }


    pt nv = v/sqrt(ds(v));
    double cosss = h/sqrt(h*h+cone.r*cone.r);

    if(cmp(nv^nh,cosss) == 0||cmp(troot, 0) == 0) {
//        cout << "caso 3A " << endl;
        return false;
    }
    else{
//        cout << "caso 3B " << endl;
        double sol = -bt / (2 * at);
        pt inter1 = A + (v * sol);
        if (!(inter1 != cone.H)) {
            return false;
        }
//        if (pointInsideCone(cone, A) || pointInSegment(A, B, B))
//            return true;
    };

    return false;
}


pt a, b;
Cone cones[55];

int main() {
    int k;

    while (true) {
        cin >> k;
        if (k == -1)
            break;

        for (int i = 0; i < k; ++i) {
            cin >> cones[i].H.x >> cones[i].H.y >> cones[i].H.z >> cones[i].r;
            cones[i].C.x = cones[i].H.x;
            cones[i].C.y = cones[i].H.y;
            cones[i].C.z = 0;
        }
        cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z;


        int i = 0;
        for (; i < k; ++i) {
            if (coneSegmentIntersection(cones[i], a, b)) {
//                cout << "WAAAT" << endl;
                break;
            }
        }

        cout << (i == k && a != b ? "Yes" : "No") << "\n";

    }


    return 0;
}

/*
1
10 2 2 2
5 2 1
15 2 1
1
0 0 10 10
0 0 11
1 1 10
2
0 0 10 10
5 5 10 10
100 100 100
101 101 101
2
10 10 2 5
10 2 2 2
10 2 3
2 2 2
1
0 0 10 10
-100 0 1
100 0 1
1
0 0 2 5
0 -8 3
-8 -8 2
1
0 0 2 2
0 0 3
-8 0 2
1
0 0 10 10
0 0 100
0 1 100
1
0 0 10 10
-1000 0 100
1000 0 100
1
0 0 10 10
-1000 0 10
1000 0 10
1
0 0 10 10
-1000 0 10
1000 0 11
1
0 0 10 10
-10 0 10
10 0 10
1
0 0 10 10
-10 0 9
10 0 9
1
0 0 10 10
-10 0 1
10 0 100000
1
0 0 10 10
-10 0 1
10 0 1000
1
0 0 10 10
-10 0 1
10 0 100
1
0 0 10 10
-10 0 1
10 0 10
1
0 0 10 10
-10 0 1
10 0 50
1
0 0 10 10
-10 0 1
10 0 25
1
0 0 10 10
-10 0 1
10 0 13
1
0 0 10 10
-10 0 1
10 0 13
1
0 0 10 10
-10 0 1
10 0 14
1
0 0 10 10
-10 0 1
10 0 15
1
0 0 10 10
-10 0 1
10 0 16
1
0 0 10 10
-10 0 1
10 0 17
1
0 0 10 10
-10 0 1
10 0 18
1
0 0 10 10
-10 0 1
10 0 19
1
0 0 1000 1000
1 1 5
2 0 4
1
0 0 1000 1000
2000 2000 3000
1 1 5
1
0 0 3 3
1 0 2
2 0 1
1
0 0 3 3
2 100 1
2 -100 1
1
0 0 10 10
-10 0 1
10 0 19
-1
 */