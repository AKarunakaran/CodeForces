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
using namespace std;
#define int long long
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

const int N = 1e6+1;
int n, m, arr[N], st[2*N], et[N], h[N], start[N], endid[N], a[N], idx = 0, path[N];
vector<int> g[N];

void dfs(int s, int p = -1, int ch = 0) {
	h[s] = ch;
	start[s] = idx;
	path[idx++] = s;
	for(int v : g[s]) if(v != p) dfs(v, s, ch+1);
	endid[s] = idx;
	path[idx++] = s;
}

void modify(int *t, int p, int value) {  // add value at position p
    for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int *t, int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(a, a+N, 0);
    fill(h, h+N, 0);
    cin >> n >> m;
    FOR(i, 1, n) cin >> arr[i];
    REP(i, n-1) {
    	int from, to;
    	cin >> from >> to;
    	g[from].push_back(to);
    	g[to].push_back(from);
    }
    dfs(1);

    // FOR(i, 1, n) cout << arr[i] << ' ';
    // cout << endl;
    // FOR(i, 1, n) cout << h[i] << ' ';
    // cout << endl;
    // REP(i, idx) cout << path[i] << ' ';
    // cout << endl;
    // FOR(i, 1, n) cout << start[i] << ' ';
    // cout << endl;
    // FOR(i, 1, n) cout << endid[i] << ' ';
    // cout << endl;

    n <<= 1;
    while(m--) {
    	int type, x;
    	cin >> type >> x;
    	if(type == 2) {
    		int sgn = 2*(h[x] & 1) - 1;
    		int res = query(et, endid[x], endid[1]+1)-query(st, endid[x], endid[1]+1);
    		cout << res*sgn+arr[x] << endl;
    	} else {
    		int val;
    		cin >> val;
    		int sgn = 2*(h[x] & 1) - 1;
    		modify(st, start[x], val*sgn);
    		modify(et, endid[x], val*sgn);
    	}
    }

    return 0;
}