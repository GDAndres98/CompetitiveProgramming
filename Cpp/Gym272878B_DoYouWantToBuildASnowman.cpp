#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct trio{
    ll a,b,c;
    trio(ll a, ll b, ll c): a(a), b(b), c(c){
    }

    bool operator <(trio x){
        if(a == x.a){
            if(b == x.b)
                return c < x.c;
            return b < x.b;
        }
        return a < x.a;
    }
    bool operator == (trio x){
        return a == x.a && b == x.b && c == x.c;
    }
};


vector<trio> sol;
ll d[10];
ll e[10];
ll a[10];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int max = 1 << n;

    ll fb , sb, tb, t, t2;
    int m, p;
    for(int i = 1; i < max; i++){
        fb = 0;
        t = 0;
        m = 0;
        for(int j = 1, k = 0; j < max; j <<= 1, k++){
            if(i&j)
                fb += a[k];
            else{
                t += a[k];
                d[m++] = a[k];
            }
        }

        if(fb >= t) continue;

        int sMax = 1 << m;
        for(int j = 1; j < sMax; j++){
            sb = 0;
            t2 = 0;
            p = 0;
            for(int l = 1, k = 0; l < sMax; l <<= 1, k++) {
                if (j & l)
                    sb += d[k];
                else {
                    t2 += d[k];
                    e[p++] = d[k];
                }
            }

            if(sb >= t2) continue;

            int tMax = 1 << p;
            for(int f = 1; f < tMax; f++){
                tb = 0;
                for(int l = 1, k = 0; l < tMax; l <<= 1, k++) {
                    if (f & l)
                        tb += e[k];
                }

                if(fb < sb && sb < tb){
                    sol.emplace_back(fb,sb,tb);
                }
            }
        }

    }

    sort(sol.begin(), sol.end());

    for(int i = 0; i < sol.size(); i++){
        if(i > 0 && sol[i] == sol[i-1]) continue;
        cout << sol[i].a << " " << sol[i].b << " " << sol[i].c << "\n";
    }

    return 0;
}
