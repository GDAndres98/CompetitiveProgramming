#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>


using namespace std;
long long INF = 9223372036854775807;
const int MAXN = 510;


vector<int> g[MAXN];
int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack<int, vector<int> > s;
int ticks = 0, current_scc = 0;

void tarjan(int u) {
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    const vector<int> &out = g[u];
    for (int k = 0, m = out.size(); k < m; ++k) {
        const int &v = out[k];
        if (d[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (stacked[v]) {
            low[u] = min(low[u], d[v]);
        }
    }
    if (d[u] == low[u]) {
        int v;
        do {
            v = s.top();
            s.pop();
            stacked[v] = false;
            scc[v] = current_scc;
        } while (u != v);
        current_scc++;
    }
}

long long mg[MAXN][MAXN];

vector<int> h[MAXN];
long long mh[MAXN][MAXN];
int n_2;


void floydWarshall() {

    for (int i = 0; i < n_2; i++)
        mh[i][i] = 0;

    for (int k = 0; k < n_2; k++)
        for (int i = 0; i < n_2; i++)
            for (int j = 0; j < n_2; j++)
                if (mh[i][k] != INF && mh[k][j] != INF) {
                    long long dt = mh[i][k] + mh[k][j];
                    if (mh[i][j] > dt)
                        mh[i][j] = dt;
                }

}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scc[i] = 0;
        d[i] = -1;
        stacked[i] = false;
        for (int j = 0; j < n; ++j) {
            mg[i][j] = INF;
            mh[i][j] = INF;
        }
    }


    int u, v;
    long long sec;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> sec;
        g[u - 1].push_back(v - 1);
        mg[u - 1][v - 1] = sec;
    }

    for (int i = 0; i < n; ++i) {
        if (d[i] == -1)
            tarjan(i);
    }

    n_2 = current_scc;
//    cout<<"n2-->"<<n_2<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
//            cout<<"NI PUTO SENTIDO"<<endl;
            u = scc[i];
            v = scc[g[i][j]];
            if (u != v) {
                if (mh[u][v] == INF)
                    h[u].push_back(v);
                mh[u][v] = min(mh[u][v], mg[i][g[i][j]]);
            }
        }
    }

//    cout << endl;
//    for (int i = 0; i < n; ++i) {
//            cout << i << " -> " << scc[i] << endl;
//    }
    floydWarshall();
//    for (int i = 0; i < n_2; ++i) {
//        for (int j = 0; j < n_2; ++j) {
//            cout << i << " -> " << j << " : " << mh[i][j] << endl;
//        }
//    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        u = scc[u - 1];
        v = scc[v - 1];
        cout << (mh[u][v] == INF ? -1 : mh[u][v]) << "\n";
    }


}

/*
10 0
8
1 2
2 3
3 4
4 5
5 6
3 1
1 7
9 8

10 4
1 2 4
2 3 4
3 1 4
4 5 4
8
1 2
2 3
3 4
4 5
5 6
3 1
1 7
9 8

10 10
1 2 4
2 3 4
3 4 4
4 5 4
5 6 4
6 7 4
7 8 4
8 9 4
9 10 4
10 1 4
8
1 2
2 3
3 4
4 5
5 6
3 1
1 7
9 8

 */