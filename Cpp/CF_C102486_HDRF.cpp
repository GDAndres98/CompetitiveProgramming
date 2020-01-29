// CF_C102486_HDRF Yandex Cup 2017

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
#define MAXN 1000010
#define MAXXX 1000010
typedef pair<int, int> pii;

int n, t[2 * MAXN], val[MAXN], arr[2 * MAXN];
vector<int> g[MAXN];
vector<pii> datass;
pii indexes[MAXN];
int maxIndex;
int idex[MAXN];
bool espacio = false;


//ifstream in("entrada.in");
//ofstream out("salida.txt");


void printNum(int x) {
    if (espacio)
        cout << " ";
    else
        espacio = true;

    cout << x;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int minim(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return MAXXX;
    if (l == tl && r == tr)
        return t[v];

    int tm = (tl + tr) / 2;
    return min(minim(v * 2, tl, tm, l, min(r, tm)), minim(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

void sol(int x) {

    vector<int> pila;
    fill(idex, idex + n + 5, -1);
    pila.push_back(x);

    while (!pila.empty()) {
        x = pila[pila.size() - 1];
        int l = indexes[x].first;
        int r = indexes[x].second;
        if (l < r) {
            int next = minim(1, 0, maxIndex, l + 1, r - 1);
            if (next == MAXXX) {

            } else {
                pila.push_back(datass[next].second);
                continue;
            }
        }
        if (r != l)
            update(1, 0, maxIndex, l, MAXXX);
        update(1, 0, maxIndex, r, MAXXX);
        printNum(x);
        pila.pop_back();
    }



//    int l = indexes[x].first;
//    int r = indexes[x].second;
//
//    if (l < r)
//        while (true) {
//            int next = minim(1, 0, maxIndex, l + 1, r - 1);
//            if (next == MAXXX)
//                break;
//            sol(datass[next].second);
//        }
//    if (r != l)
//        update(1, 0, maxIndex, l, MAXXX);
//    update(1, 0, maxIndex, r, MAXXX);
//    printNum(x);
}

void dfs(int x) {

    vector<int> pila;
    fill(idex, idex + n + 5, -1);

    pila.push_back(x);
    while (!pila.empty()) {
        x = pila[pila.size() - 1];
        if (idex[x] == -1) {
            idex[x] = 0;
            indexes[x].first = maxIndex;
            arr[maxIndex] = val[x];
        }
        if (idex[x] < g[x].size()) {
            maxIndex++;
            pila.push_back(g[x][idex[x]]);
            idex[x]++;
            continue;
        }
        if (!g[x].empty()) {
            maxIndex++;
            arr[maxIndex] = val[x];
        }
        indexes[x].second = maxIndex;
        pila.pop_back();
    }
    //--------------------------------
//    indexes[x].first = maxIndex;
//    arr[maxIndex] = val[x];
//    for (int i : g[x]) {
//        maxIndex++;
//        dfs(i);
//    }
//    if (!g[x].empty()) {
//        maxIndex++;
//        arr[maxIndex] = val[x];
//    }
//    indexes[x].second = maxIndex;

}


bool compareElements1(pii &i1, pii &i2) {
    return i1.first < i2.first;
}


int main() {

    in >> n;
    int x;
    for (int i = 2; i <= n; ++i) {
        in >> x;
        g[x].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        in >> x;
        datass.emplace_back(x, i);
    }

    sort(datass.begin(), datass.end(), compareElements1);

    for (int i = 0; i < n; ++i) {
        datass[i].first = i;
        val[datass[i].second] = i;
    }

    maxIndex = 0;


    dfs(1);
//    for (int k = 0; k <= maxIndex; ++k) {
//        cout << arr[k] << " ";
//    }
    //cout << endl << maxIndex << endl;

    build(arr, 1, 0, maxIndex);


    //cout << minim(1, 0, maxIndex, maxIndex - 5, maxIndex) << endl;
    //cout << minim(1, 0, maxIndex, maxIndex - 3, maxIndex) << endl;

    //cout << "Hello, World!" << endl;

    sol(1);


    return 0;
}


/*
 *
6
4 4 1 1 5
4 6 3 2 5 1

--6 3 2 4 5 1


14
1 2 2 2 1 6 7 1 9 10 11 10 13
7 1 11 8 14 9 3 6 5 4 12 13 10 2

--4 3 5 2 14 8 7 13 12 11 10 9 6 1
 *
 */