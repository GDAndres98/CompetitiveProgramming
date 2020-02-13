// UVA 11909
// UVa11909_SoyaMilk

#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.14159265359


using namespace std;

int main() {
    double l, w, h, t;
    double area;
    while (cin>>l>>w>>h>>t) {


        double areaA = l * h;
        t = (t * PI) / 180.0;
        if (t < atan(h / l)) {
            double x = PI - t - PI / 2;
            double z = (l * sin(t)) / sin(x);
            double areaB = (l * z) / 2.0;
            area = (areaA - areaB) * w;
        } else {
            t = PI/2-t;
            double x = PI - t - PI / 2;
            double z = (h * sin(  t)) / sin(x);
            area = ((h * z) / 2.0) * w;
        };
        cout << fixed << setprecision(3) << area << " mL" << endl;
    }


    return 0;
}
/*
 *
1 2 3 4
1 2 3 4
1 2 3 4

 */