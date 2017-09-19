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

int n, ans[200001] = {}, a[200001] = {}, d[200001] = {};
vector<int> g[200001];

void dfs(int src, int par, int depth) {
    for(int i = 1; i*i <= a[src]; ++i) {
        if(a[src] % i == 0) {
            ++d[i];
            if(i*i != a[src]) ++d[a[src]/i];
        }
    }
    //DEBUG(src);
    //DEBUG(depth);
    //FOR(i, 1, 10) cout << d[i] << " ";
    //cout << endl;
    FORD(i, max(a[src], a[par]), 1) {
        if(d[i] >= depth-1) {
            ans[src] = i;
            break;
        }
    }
    for(int v : g[src]) {
        if(v == par) continue;
        dfs(v, src, depth+1);
    }
    for(int i = 1; i*i <= a[src]; ++i) {
        if(a[src] % i == 0) {
            --d[i];
            if(i*i != a[src]) --d[a[src]/i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n) cin >> a[i+1];
    REP(i, n-1) {
    	int x, y;
    	cin >> x >> y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    dfs(1, -1, 0);
    FOR(i, 1, n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}