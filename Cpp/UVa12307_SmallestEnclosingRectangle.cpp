// UVa12307_SmallestEnclosingRectangle
// Falla en Precisión
#define PI 3.14159265359

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define MAX 60000

using namespace std;

struct pt {
    double x, y;

    double operator*(const pt &a) const {
        return x - a.x;
    }

    string toString() {
        return to_string(x) + ", " + to_string(y);
    }

};

struct seg {
    pt A, B;

};

int n, nPoints;
double minAngle;
double callAng[4];
int callIdx[4];
pt auxPoints[4];
pt tempPoints[4];
pt answerPoints[4];
vector<seg> segments;

double minArea = 200010.0 * 200010.0;
double minPerim = 200010.0 * 4.0;


bool areTheOriginals() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
        }
    }
    return true;
}

double subAngle(int i) {
    return atan2(segments[(i + 1) % nPoints].B.y - segments[i].B.y, segments[(i + 1) % nPoints].B.x - segments[i].B.x) -
           atan2(segments[i].A.y - segments[i].B.y, segments[i].A.x - segments[i].B.x) - PI;

}


pt rotate(pt o, pt p, double ang) {
    pt res;
    res.x = o.x + cos(ang) * (p.x - o.x) - sin(ang) * (p.y - o.y);
    res.y = o.y + sin(ang) * (p.x - o.x) + cos(ang) * (p.y - o.y);
    return res;
}

pt intLineas(pt a1, pt b1, pt a2, pt b2) {
    double xa2 = b1.x - a1.x, xb2 = b2.x - a2.x, xc = a1.x - a2.x, ya2 = b1.y - a1.y, yb2 = b2.y - a2.y, yc =
            a1.y - a2.y, d = yb2 * xa2 - xb2 * ya2, zz = xb2 * yc - yb2 * xc;
    return {a1.x + xa2 * zz / d, a1.y + ya2 * zz / d};
}

double areaRectangle() {
    double res = 0;
    for (int i = 0, j = 1; i < 4; ++i, j = (j + 1) % 4)
        res += tempPoints[i].x * tempPoints[j].y - tempPoints[i].y * tempPoints[j].x;
    return abs(res) / 2.0;
}

double perimeterRectangle(){
    double res = 0;
    for (int i = 0, j = 1; i < 4; ++i, j = (j + 1) % 4)
        res += hypot(tempPoints[i].x - tempPoints[j].x, tempPoints[i].y - tempPoints[j].y);
    return res;
}


void getNewAnswer() {

    for (int i = 0; i < 4; ++i) {
        if (callAng[i] < 10e-6) {
            auxPoints[i].x = segments[callIdx[i]].B.x;
            auxPoints[i].y = segments[callIdx[i]].B.y;
        } else
            auxPoints[i] = rotate(segments[callIdx[i]].A, segments[callIdx[i]].B, callAng[i]);
    }
    for (int i = 0; i < 4; ++i) {
        tempPoints[i] = intLineas(segments[callIdx[i]].A, auxPoints[i], segments[callIdx[(i + 1) % 4]].A,
                                  auxPoints[(i + 1) % 4]);
//        cout << "Punto " << i << ": " << tempPoints[i].toString() << endl;
    }
    double tempArea = areaRectangle();
    double tempPerim = perimeterRectangle();
    if (minArea > tempArea && abs(tempArea - minArea) > 10e-8) {
        minArea = tempArea;
    }
    if (minPerim > tempPerim && abs(tempPerim - minPerim) > 10e-8) {
        minPerim = tempPerim;
    }

}


void printInDegrees(double x) {
    cout << x * 180 / PI << endl;
}

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void convex_hull(vector<pt> &a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int) a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int) up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

int main() {

    segments.reserve(100005);
    while (true) {
        cin >> n;
        if (!n)
            break;
        segments.clear();
        fill(callAng,callAng+4,0.0);
        fill(callIdx,callIdx+4,0);

        minArea = 200010.0 * 200010.0;
        minPerim = 200010.0 * 4.0;
        double x, y;
        vector<pt> points;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            points.push_back({x, y});
        }

        convex_hull(points);
        nPoints = points.size();

        callIdx[0] = 0;  // top
        callIdx[1] = 0;  // right
        callIdx[2] = 0;   // down
        callIdx[3] = 0;   // left

        for (int i = 0; i < nPoints; ++i) {
            segments.push_back({points[i], points[(i + 1) % nPoints]});
            if (points[i].y > points[callIdx[0]].y)
                callIdx[0] = i;
            if (points[i].x > points[callIdx[1]].x)
                callIdx[1] = i;
            if (points[i].y < points[callIdx[2]].y)
                callIdx[2] = i;
            if (points[i].x < points[callIdx[3]].x)
                callIdx[3] = i;
        }

//    for (int i = 0; i < 4; ++i) {
//        cout << points[callIdx[i]].x << " " << points[callIdx[i]].y << endl;
//    }




        callAng[0] = -atan((segments[callIdx[0]].B.y - segments[callIdx[0]].A.y) /
                           (segments[callIdx[0]].B.x - segments[callIdx[0]].A.x));
        if (callAng[0] < 0)
            callAng[0] += PI;

        callAng[1] = atan((segments[callIdx[1]].B.x - segments[callIdx[1]].A.x) /
                          (segments[callIdx[1]].B.y - segments[callIdx[1]].A.y));
        if (callAng[1] < 0)
            callAng[1] += PI;

        callAng[2] = -atan((segments[callIdx[2]].B.y - segments[callIdx[2]].A.y) /
                           (segments[callIdx[2]].B.x - segments[callIdx[2]].A.x));
        if (callAng[2] < 0)
            callAng[2] += PI;

        callAng[3] = atan((segments[callIdx[3]].B.x - segments[callIdx[3]].A.x) /
                          (segments[callIdx[3]].B.y - segments[callIdx[3]].A.y));
        if (callAng[3] < 0)
            callAng[3] += PI;

//    printInDegrees(callAng[0]);
//    printInDegrees(callAng[1]);
//    printInDegrees(callAng[2]);
//    printInDegrees(callAng[3]);

        getNewAnswer();

        for (int i = 0; i < nPoints + 1; ++i) {
            minAngle = callAng[0];
            for (int i = 0; i < 4; ++i)
                minAngle = min(minAngle, callAng[i]);
            for (int i = 0; i < 4; ++i) {
                if (callAng[i] - minAngle < 10e-10) {
                    callAng[i] = -subAngle(callIdx[i]);
                    while (callAng[i] > 2 * PI) {
                        callAng[i] -= 2 * PI;
                    }
                    callIdx[i] = (callIdx[i] + 1) % nPoints;
                } else {
                    callAng[i] -= minAngle;
                }
            }
            getNewAnswer();
//        cout<<"Wenas"<<endl;
//        printInDegrees(callAng[0]);
//        printInDegrees(callAng[1]);
//        printInDegrees(callAng[2]);
//        printInDegrees(callAng[3]);
        }

//    cout << "Min Area: " << minArea << endl;

//    cout << "Rotado 0: " << (rotate(segments[callIdx[0]].A, segments[callIdx[0]].B, callAng[0])).toString() << endl;
//    cout << "Rotado 1: " << (rotate(segments[callIdx[1]].A, segments[callIdx[1]].B, callAng[1])).toString() << endl;
//    cout << "Rotado 2: " << (rotate(segments[callIdx[2]].A, segments[callIdx[2]].B, callAng[2])).toString() << endl;
//    cout << "Rotado 3: " << (rotate(segments[callIdx[3]].A, segments[callIdx[3]].B, callAng[3])).toString() << endl;

//    for (int i = 0; i < points.size(); ++i) {
//        cout << points[i].x << " " << points[i].y << endl;
//    }

        sort(answerPoints, answerPoints + 4, &cmp);
        vector<pt> answerrr;
        answerrr.push_back(answerPoints[0]);
        answerrr.push_back(answerPoints[1]);
        answerrr.push_back(answerPoints[2]);
        answerrr.push_back(answerPoints[3]);
        convex_hull(answerrr);
        for (int i = 3; i >= 0; --i) {
        }


        cout << fixed << setprecision(2) << minArea << " " << minPerim << endl;

//    tempPoints[0] = {0.0000000000, 0.0000000000};
//    tempPoints[1] = {1.0000000000, -1.0000000000};
//    tempPoints[2] = {3.0000000000, 1.0000000000};
//    tempPoints[3] = {2.0000000000, 2.0000000000};
//
//    cout << areaRectangle()<<endl;

    }
    return 0;
}




/*
 *
3
0 0
2 2
2 0

3
0 0
2 0
0 2

3
0 0
2 2
0 2

3
2 2
2 0
0 2


3
8 8
10 7
7 11


6
1 1
0 0
0 2
0 1
2 2
2 0

5
1 3
4 5
8 4
7 1
3 2


 */