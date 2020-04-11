//SPOJ_TAP2013G_War
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

int a[100010];
int b[100010];
vector<int> numbers;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    int idxA = n - 1;
    int idxB = n - 1;
    int cont = 0;
    while (idxA >= 0 && idxB >= 0) {
        if (b[idxB] >= a[idxA]) {
            idxB--;
        } else {
            idxA--;
            idxB--;
            cont++;
        }
    }


    cout << cont << endl;

}
/*
20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/