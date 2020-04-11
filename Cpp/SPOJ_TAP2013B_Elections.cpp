//SPOJ_TAP2013B_Elections
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stdio.h>

#define PI 3.14159265359
#define DUM 10111.0
#define MAX 100010

using namespace std;

double v[50];
vector<int> numbers;

int main() {
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }

    sort(v, v + n);
    double mx = v[n - 1];
    bool una = false;
    if (45 * sum / 100 <= mx) {
        una = true;
    } else if (40 * sum / 100 <= mx) {
        int j = 0;
        double diez = 10 * sum / 100;
        for (j = 0; j < n - 1; ++j) {
            if (mx < v[j]+diez) {
                break;
            }
        }
        if (j == n - 1)
            una = true;
    }

    cout << (una ? 1 : 2) << endl;

}
/*
20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/