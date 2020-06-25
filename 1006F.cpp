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
const int N = 20;
ll n, m, k, g[N][N];
unordered_map<ll, ll> mp[N][N];

ll rec(int r, int c, ll t) {
	auto& cur = mp[r][c];
	if(cur.find(t) != cur.end()) return cur[t];
	ll& memo = cur[t];
	if(!r && !c) {
		if(t == 0) return memo = 1;
		else return memo = 0;
	}
	ll res = 0;
	if(r) res += rec(r-1, c, t ^ g[r-1][c]);
	if(c) res += rec(r, c-1, t ^ g[r][c-1]);
	return memo = res;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> k;
    REP(i, n) REP(j, m) cin >> g[i][j];
    cout << rec(n-1, m-1, k ^ g[n-1][m-1]) << endl;

    return 0;
}