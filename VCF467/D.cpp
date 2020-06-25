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

/////////////////////////////////////////////////////////////////////

int n, m, s;
vector<bool> cycPart, vis, vis0, good;
vector<vector<int>> g, tlg;
vector<int> ans;

int getTlgIdx(int v, int par) {
    return v+n*par;
}

int getOrig(int v) {
    return v <= n ? v : v - n;
}

bool dfs(int src) {
    if(good[src]) {
        ans.push_back(getOrig(src));
        return true;
    }
    vis0[src] = 1;
    for(int v : tlg[src]) {
        if(!vis0[v] && dfs(v)) {
            ans.push_back(getOrig(src));
            return true;
        }
    }
    return false;
}

bool cycDfs(int src) {
    if(cycPart[src]) return true;
    vis[src] = 1;
    for(int v : g[src]) {
        if(!vis[v] && cycDfs(v)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    vector<vector<int>> rg(n+1);
    g.resize(n+1), tlg.resize(1+2*n);
    vector<int> deg(n+1, 0);
    vis.resize(1+n, 0);
    vis0.resize(1+n+n, 0);
    good.resize(1+n+n, 0);
    queue<int> next;
    FOR(i, 1, n) {
        int c;
        cin >> c;
        deg[i] = c;
        if(c == 0) {
            next.push(i);
            good[getTlgIdx(i, 1)] = 1;
        }
        REP(j, c) {
            int e;
            cin >> e;
            g[i].push_back(e);
            rg[e].push_back(i);

            tlg[getTlgIdx(i, 0)].push_back(getTlgIdx(e, 1));
            tlg[getTlgIdx(i, 1)].push_back(getTlgIdx(e, 0));
        }
    }
    cin >> s;

    if(dfs(getTlgIdx(s, 0))) {
        cout << "Win" << endl;
        reverse(ans.begin(), ans.end());
        for(int v : ans) cout << v << ' ';
        cout << endl;
        exit(0);
    }

    // Find if Draw
    cycPart.resize(n+1, 1);
    while(!next.empty()) {
    	int cur = next.front();
        next.pop();
    	cycPart[cur] = false;
    	for(int v : rg[cur]) {
    		--deg[v];
    		if(deg[v] == 0) next.push(v);
    	}
    }
    cout << (cycDfs(s) ? "Draw" : "Lose") << endl;

    return 0;
}