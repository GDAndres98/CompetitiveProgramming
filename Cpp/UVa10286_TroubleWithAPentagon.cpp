// UVA 10286
// UVa10286_Trouble with a Pentagon

#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.14159265359


using namespace std;

double sin_deg(double deg) {
    return sin((deg * PI) / 180.0);
}


int main() {
    double l;
    while (cin >> l) {
        cout << fixed << setprecision(10) << (l*sin_deg(108) / (sin_deg(63))) << endl;
    }
}
/*
 *
1 2 3 4
1 2 3 4
1 2 3 4

 */