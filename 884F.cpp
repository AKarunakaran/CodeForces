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
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

////////////////////////////////////////////////////////////////////

const int MAXN = 2100;
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
    queue<int> Q;
    Q.push(s);
    z[s] = true;
    while (!Q.empty()) {
        int i = Q.front();
        Q.pop();
        for (auto p = g[i].begin(); p != g[i].end(); ++p) {
            if (p->f > 0 && d[p->v] > d[i] + p->w) {
                d[p->v] = d[i] + p->w;
                fa[p->v] = i;
                ff[p->v] = p - g[i].begin();
                if (!z[p->v]) {
                    z[p->v] = true;
                    Q.push(p->v);
                }
            }
        }
        z[i] = false;
    }
    return d[t];
}

int min_cost(int s, int t, int n) {
    int flow = 0, cost = 0;
    while (SPFA(s, t, n) < 0) { //if using negative cost, replace INF with 0
        int i = t, now = INF;
        while (i != s) {
            node &p = g[fa[i]][ff[i]];
            i = fa[i];
            if (p.f < now) now = p.f;
        }
        flow += now;
        
        i = t;
        while (i != s) {
            g[fa[i]][ff[i]].f -= now;
            cost += now * g[fa[i]][ff[i]].w;
            g[i][g[fa[i]][ff[i]].couple].f += now;
            i = fa[i];
        }
    }
    return cost;
}

int n;

int halfLayerIdx(int c, int i) {
	return 2*n+26+c*n/2+i;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    /*
    1 - n: normal word
    n+1 - 2*n: output word
	2*n+1 - 2*n+26: letters
	2*n+26+i*n/2+1 - 2*n+26+i*n/2+n/2: half layer for letter i (zero-indexed)
	2*n+26+25*n/2+n/2 + 1: src
	2*n+26+25*n/2+n/2 + 2: tgt
    */
    string s;
    cin >> n >> s;
    int src = 2*n+26+25*n/2+n/2 + 1;
    int tgt = src+1;
    FOR(i, 1, n) {
    	newnode(src, i, 1, 0);
    	newnode(i, 2*n+(s[i-1]-'a'+1), 1, 0);
    	newnode(n+1, tgt, 1, 0);
    }
    FOR(c, 0, 25) {
    	FOR(i, 1, n/2) {
    		newnode(2*n+c+1, getHalfLayerIdx(c, i), 1, 0);
    		if()
    	}
    }
    cout << -min_cost(src, tgt, tgt) << endl;

    return 0;
}