//	UVa10566_CrossedLadders
#define PI 3.14159265359

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cmath>

#define MAX 60000
#define EPS 10e-7

using namespace std;

double x, y, c;

double f(double z) {
    double tx = acos(z / x);
    double ty = acos(z / y);
    double tz = PI - tx - ty;

    double ly = z * sin(ty) / sin(tz);
    double lx = z * sin(tx) / sin(tz);

    double s = (z + ly + lx) / 2;

    return 2 * sqrt(s * (s - z) * (s - ly) * (s - lx)) / z;


}


double bicection() {
    double a = 10e-5;
    double b = y - 10e-8;
    double m;
    while(b-a>EPS){
        m = (a+b)/2;
        if(f(m)>=c){
            a=m;
        }
        else{
            b=m;
        }



    }



    return m;
}


int main() {
//    x = 10;
//    y = 10;
//    cout << f(9.798) << endl;

    while (cin >> x >> y >> c) {
        if (x < y) {
            double t = x;
            x = y;
            y = t;
        }
        double m = bicection();

        cout<<fixed<<setprecision(3)<<m<<endl;

    }

    return 0;
}

