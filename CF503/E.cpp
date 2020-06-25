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
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 1e6+10;
int n, m, q[N], nq[N];
vector<int> g[N], ans;
set<int> lft;

void solve(int s) {
    lft.erase(s);
    for(int v : g[s]) lft.erase(v);
    if(lft.size()) solve(*lft.begin());
    if(!nq[s]) {
        q[s] = nq[s] = 1;
        for(int v : g[s]) nq[v] = 1;
        ans.push_back(s);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(q, 0, sizeof(q));
    memset(nq, 0, sizeof(nq));
    cin >> n >> m;
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    FOR(i, 1, n) lft.insert(i);
    solve(1);
    cout << ans.size() << endl;
    for(int x : ans) cout << x << ' ';
    cout << endl;

    return 0;
}