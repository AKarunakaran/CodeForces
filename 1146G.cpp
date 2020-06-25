#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
// const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int MAXN = 1100;
const int INF = 1000000000;

class node {
public:
    int v, w, f, couple;
    node(int V, int W, int F, int CC) {v = V; w = W; f = F; couple = CC;};
};

int fa[MAXN], ff[MAXN];
vector<node> g[MAXN];

// s, t, capacity, cost
void newnode(int a, int b, int c, int d) {
    node p(b, d, c, g[b].size());
    node q(a, -d, 0, g[a].size());
    g[a].push_back(p);
    g[b].push_back(q);
}

int SPFA(int s, int t, int n) {
    vector<int> d(n + 1, INF);
    vector<bool> z(n + 1, false);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    z[s] = true;
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        for(auto p = g[i].begin(); p != g[i].end(); ++p) {
            if(p->f > 0 && d[p->v] > d[i] + p->w) {
                d[p->v] = d[i] + p->w;
                fa[p->v] = i;
                ff[p->v] = p - g[i].begin();
                if(!z[p->v]) {
                    z[p->v] = true;
                    q.push(p->v);
                }
            }
        }
        z[i] = false;
    }
    return d[t];
}

int min_cost(int s, int t, int n) {
    int flow = 0, cost = 0;
    while(SPFA(s, t, n) < INF) {
        int i = t, now = INF;
        while(i != s) {
            node &p = g[fa[i]][ff[i]];
            i = fa[i];
            if(p.f < now) now = p.f;
        }
        flow += now;
        
        i = t;
        while(i != s) {
            g[fa[i]][ff[i]].f -= now;
            cost += now * g[fa[i]][ff[i]].w;
            g[i][g[fa[i]][ff[i]].couple].f += now;
            i = fa[i];
        }
    }
    return cost;
}

/************************************************                       end                                ********************************************/

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)

